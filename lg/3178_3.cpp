#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100006;
long long v[N],vt[N],at[N],fa[N],dep[N],son[N],top[N],size[N],n,m;
struct node{
	long long next,to;
}e[N];
long long head[N],atot,etot,t[4*N],lazytag[4*N];
void adde(long long x,long long y)
{
	e[++etot].next=head[x];
	e[etot].to=y;
	head[x]=etot;
}
void dfs1(long long x,long long f)
{
	dep[x]=dep[f]+1;
	fa[x]=f;
	size[x]=1;long long i,maxs=-1;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs1(e[i].to,x);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>maxs)
		{
			maxs=size[e[i].to];son[x]=e[i].to;
		}
	}
}
void dfs2(long long x,long long t)
{
	top[x]=t;
	at[x]=++atot;
	vt[atot]=v[x];
	if(!son[x]) return;
	dfs2(son[x],t);
	long long i;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==fa[x]||e[i].to==son[x]) continue;
		dfs2(e[i].to,e[i].to);
	}
}
void build(long long x,long long l,long long r)
{
	if(l==r)
	{
		t[x]=vt[l];return;
	}
	long long mid=l+(r-l>>1);
	build(x<<1,l,mid); build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1|1]; 
}
void pushdown(long long x,long long l,long long r)
{
	if(!lazytag[x]) return;
	lazytag[x<<1]+=lazytag[x];
	lazytag[x<<1|1]+=lazytag[x];
	long long mid=l+(r-l>>1);
	t[x<<1]+=lazytag[x]*(mid-l+1);
	t[x<<1|1]+=lazytag[x]*(r-mid);
	lazytag[x]=0;
}
void changep(long long x,long long l,long long r,long long tar,long long v)
{
	if(l>tar||r<tar) return;
	if(l==r&&r==tar)
	{
		t[x]+=v;return;
	}
	long long mid=l+(r-l>>1);
	if(mid>=tar) changep(x<<1,l,mid,tar,v);
	if(mid<tar) changep(x<<1|1,mid+1,r,tar,v);
	t[x]=t[x<<1]+t[x<<1|1];	
}
void change(long long x,long long l,long long r,long long ll,long long rr,long long v)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		lazytag[x]+=v;t[x]+=v*(r-l+1);
		return;
	}
	pushdown(x,l,r);
	long long mid=l+(r-l>>1);
	if(mid>=ll) change(x<<1,l,mid,ll,rr,v);
	if(mid<rr) change(x<<1|1,mid+1,r,ll,rr,v);
	t[x]=t[x<<1]+t[x<<1|1];
}

long long res;
void add(long long x,long long l,long long r,long long ll,long long rr)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		res+=t[x];return;
	}
	long long mid=l+(r-l>>1);
	pushdown(x,l,r);
	if(mid>=ll) add(x<<1,l,mid,ll,rr);
	if(mid<rr) add(x<<1|1,mid+1,r,ll,rr);
}
long long query(long long x)
{
	long long ans=0;
	while(top[x]!=1)
	{
		res=0;
		add(1,1,n,at[top[x]],at[x]);ans+=res;
		x=fa[top[x]];
	}
	res=0;
	add(1,1,n,1,at[x]);
	return ans+res;
}
struct node2{
	void execute(int x)
	{
		printf("%lld\n",query(x));
	}
}world;
int main()
{
	scanf("%lld%lld",&n,&m);
	long long i,k,x,y;
	for(i=1;i<=n;i++)
		scanf("%lld",&v[i]);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		adde(x,y);adde(y,x);
	}
	dfs1(1,0);dfs2(1,1);
	build(1,1,n);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&x);
		int me=x;
		if(k==1)
		{
			scanf("%lld",&y);
			changep(1,1,n,at[x],y);
		}
		else if(k==2)
		{
			scanf("%lld",&y);
			change(1,1,n,at[x],at[x]+size[x]-1,y);
		}
		else if(k==3)
		{
			world.execute(me);
		}
	}
	return 0;
	
}

#include<cstdio>
#include<algorithm>
using namespace std;
const int N=4000007;
int t[4*N],dep[4*N],fa[4*N],size[4*N],top[4*N],son[4*N],at[4*N],v[4*N],head[4*N],vt[4*N],lazytag[4*N],etot,atot,n,m,r,p;
struct node{						//at[i]:iÏÖÔÚµÄ±àºÅ 
	int next,to;
}e[4*N];
void adde(int x,int y)
{
	e[++etot].next=head[x];
	e[etot].to=y;
	head[x]=etot;
}


void dfs1(int x,int f)
{ 
	dep[x]=dep[f]+1;
	fa[x]=f;
	size[x]=1;
	int i,maxs=-1;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs1(e[i].to,x);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>maxs)
		{
			maxs=size[e[i].to];
			son[x]=e[i].to;
		}
	}
}
void dfs2(int x,int t)
{
	at[x]=++atot;
	top[x]=t;vt[at[x]]=v[x];
	if(!son[x]) return;
	dfs2(son[x],t);
	int i;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==fa[x]||e[i].to==son[x]) continue;
		dfs2(e[i].to,e[i].to);
	}
}


void build(int x,int l,int r)
{
	if(l==r) 
	{
		t[x]=vt[l];
		return;
	}
	int mid=l+(r-l>>1);
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[x]=(t[x<<1]+t[x<<1|1])%p;
}
void pushdown(int x,int l,int r)
{
	if(!lazytag[x]) return;
	lazytag[x<<1]+=lazytag[x];
	lazytag[x<<1|1]+=lazytag[x];
	lazytag[x<<1]%=p;lazytag[x<<1|1]%=p;
	int mid=l+(r-l>>1);
	t[x<<1]=(t[x<<1]+lazytag[x]*(mid-l+1))%p;
	t[x<<1|1]=(t[x<<1|1]+lazytag[x]*(r-mid))%p;
	lazytag[x]=0; 
} 
void change1p(int x,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		t[x]=(t[x]+v*(r-l+1))%p;
		lazytag[x]=(lazytag[x]+v)%p;
		return;
	}
	pushdown(x,l,r);
	int mid=l+(r-l>>1);
	if(ll<=mid) change1p(x<<1,l,mid,ll,rr,v);
	if(rr>mid) change1p(x<<1|1,mid+1,r,ll,rr,v);
	t[x]=(t[x<<1]+t[x<<1|1])%p;
}

long long add(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return 0;
	if(l>=ll&&r<=rr)
	{
		return t[x]%p;
	}
	pushdown(x,l,r);long long res=0;
	int mid=l+(r-l>>1);
	if(ll<=mid) res=add(x<<1,l,mid,ll,rr)%p;
	if(rr>mid) res=(res+add(x<<1|1,mid+1,r,ll,rr))%p;
	return res;
}


void change1(int x,int y,int v)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		change1p(1,1,n,at[top[x]],at[x],v);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	change1p(1,1,n,at[x],at[y],v);
}
void change2(int x,int v)
{
	change1p(1,1,n,at[x],at[x]+size[x]-1,v);
}


long long query1(int x,int y)
{
	long long ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=(ans+add(1,1,n,at[top[x]],at[x]))%p;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	ans=(ans+add(1,1,n,at[x],at[y]))%p;
	return ans;
}
long long query2(int x)
{
	return add(1,1,n,at[x],at[x]+size[x]-1)%p;
}


int main()
{
	scanf("%d%d%d%d",&n,&m,&r,&p);
	int i,x,y,z,k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);v[i]%=p;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	}
	dfs1(r,0);
	dfs2(r,r);
	build(1,1,n);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d%d",&x,&y,&z);
			change1(x,y,z);
		}
		else if(k==2)
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",query1(x,y)%p);
		} 
		else if(k==3)
		{
			scanf("%d%d",&x,&y);
			change2(x,y);
		}
		else if(k==4)
		{
			scanf("%d",&x);
			printf("%d\n",query2(x)%p);
		}
	}
	return 0;
}

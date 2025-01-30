#include<cstdio>
#include<algorithm>
const int N=200007;
int v[N],vt[N],dep[N],fa[N],size[N],son[N],top[N],at[N];
struct node{
	int next,to;
}e[N];
int head[N],etot,atot,n,m;
int t[4*N],lazytag[4*N];

void adde(int x,int y)
{
	e[++etot].next=head[x];
	e[etot].to=y;
	head[x]=etot;
} 

void dfs1(int x,int f)
{
	fa[x]=f;
	dep[x]=dep[f]+1;
	size[x]=1;int i,maxs=-1;
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

void dfs2(int x,int t)
{
	top[x]=t;
	at[x]=++atot;vt[atot]=v[x];
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
		t[x]=vt[l];return;
	}
	int mid=l+(r-l>>1);
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1|1];
}

void pushdown(int x,int l,int r)
{
	if(!lazytag[x]) return;
	lazytag[x<<1]+=lazytag[x];
	lazytag[x<<1|1]+=lazytag[x];
	int mid=l+(r-l>>1);
	t[x<<1]+=lazytag[x]*(mid-l+1);
	t[x<<1|1]+=lazytag[x]*(r-mid);
	lazytag[x]=0;
}

//bool flag;
void change1(int x,int l,int r,int tar,int v)
{
	if(l>tar||r<tar) return;
	if(l==r&&r==tar)
	{
		t[x]+=v;
		return;
	}
	int mid=l+(r-l>>1);
	if(mid>=tar) change1(x<<1,l,mid,tar,v);
	if(mid<tar) change1(x<<1|1,mid+1,r,tar,v);
	t[x]=t[x<<1]+t[x<<1|1];
}

void change2(int x,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		lazytag[x]+=v;
		t[x]+=v*(r-l+1);return;
	}
	pushdown(x,l,r);
	int mid=l+(r-l>>1);
	if(mid>=ll) change2(x<<1,l,mid,ll,rr,v);
	if(mid<rr) change2(x<<1|1,mid+1,r,ll,rr,v); 
	t[x]=t[x<<1|1]+t[x<<1];
}

int add(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return 0;
	if(l>=ll&&r<=rr) return t[x];
	int ans=0;
	pushdown(x,l,r);
	int mid=l+(r-l>>1);
	if(mid>=ll) ans=add(x<<1,l,mid,ll,rr);
	if(mid<rr) ans+=add(x<<1|1,mid+1,r,ll,rr);
	return ans;
}

int query(int x)
{
	int ans=0;
	while(top[x]!=1)
	{
		ans+=add(1,1,n,at[top[x]],at[x]);
		x=fa[top[x]];
	}
	if(at[x]<at[1]) ans+=add(1,1,n,at[x],at[1]);
	else ans+=add(1,1,n,at[1],at[x]);
	return ans;
}

int main()
{
	int i,k,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	}
	dfs1(1,0);dfs2(1,1);
	build(1,1,n);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&k);
		if(k==1)
		{
			
			scanf("%d%d",&x,&y);
			change1(1,1,n,at[x],y);
		}
		else if(k==2)
		{
			scanf("%d%d",&x,&y);
			change2(1,1,n,at[x],at[x]+size[x]-1,y);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",query(x));
		}
	}
	return 0;
}

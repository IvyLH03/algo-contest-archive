#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000007;
int t[N<<2],a[N],nw[N],head[N],lazytag[N<<2],siz[N],fa[N],son[N],etot,dep[N],atot,af[N],n,q,s,Mod,ac[N],top[N];
struct node{
	int next,to;
}e[N<<1];
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	head[x]=etot;
}
void dfs1(int x,int f)
{
	fa[x]=f;siz[x]=1;dep[x]=dep[f]+1;
	int maxs=0;
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs1(e[i].to,x);
		siz[x]+=siz[e[i].to]; 
		if(siz[e[i].to]>maxs)
		{
			maxs=siz[e[i].to];son[x]=e[i].to;
		}
	}
 } 
void dfs2(int x,int topf)
{
	nw[x]=++atot;a[atot]=af[x];
	top[x]=topf;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].to==son[x]||e[i].to==fa[x]) continue;
		dfs2(e[i].to,e[i].to);
	 } 
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=a[l];return;
	}
	int mid=l+(r-l>>1);
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1|1];
}
void pushdown(int x,int l,int r)
{
	if(!lazytag[x]) return;
	int mid=l+(r-l>>1);
	lazytag[x<<1]=(lazytag[x<<1]+lazytag[x])%Mod;
	lazytag[x<<1|1]=(lazytag[x<<1|1]+lazytag[x])%Mod;
	t[x<<1]=(t[x<<1]+(lazytag[x]*(mid-l+1)))%Mod;
	t[x<<1|1]=(t[x<<1|1]+(lazytag[x]*(r-mid)))%Mod;
	lazytag[x]=0;
}
void change(int x,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		t[x]=t[x]+v*(r-l+1)%Mod;
		lazytag[x]=lazytag[x]+v%Mod;
		return;
	}
	pushdown(x,l,r);
	int mid=l+(r-l>>1);
	if(mid>=ll) change(x<<1,l,mid,ll,rr,v);
	if(mid<rr) change(x<<1|1,mid+1,r,ll,rr,v);
	t[x]=(t[x<<1]+t[x<<1|1])%Mod;
}
int query(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return 0;
	if(l>=ll&&r<=rr) return t[x];
	pushdown(x,l,r);
	int mid=l+(r-l>>1),s=0;
	if(mid>=ll) s=query(x<<1,l,mid,ll,rr)%Mod;
	if(mid<rr) s=s+query(x<<1|1,mid+1,r,ll,rr)%Mod;
	t[x]=(t[x<<1]+t[x<<1|1])%Mod;
	return s%Mod;
}
void caddq(int x,int y,int v)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		change(1,1,n,nw[top[x]],nw[x],v);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	change(1,1,n,nw[x],nw[y],v);
}
int qaddq(int x,int y)
{
	int s=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		s=(s+query(1,1,n,nw[top[x]],nw[x]))%Mod;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return (s+query(1,1,n,nw[x],nw[y]))%Mod;
}
int main()
{
	scanf("%d%d%d%d",&n,&q,&s,&Mod);
	int k,x,y,v;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&af[i]);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	}
	dfs1(s,0);
	dfs2(s,s);
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d%d",&x,&y,&v);
			caddq(x,y,v);
		}
		else if(k==2)
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",qaddq(x,y));
		}
		else if(k==3)
		{
			scanf("%d%d",&x,&v);
			change(1,1,n,nw[x],nw[x]+siz[x]-1,v);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",query(1,1,n,nw[x],nw[x]+siz[x]-1));                           
		}
		
	}
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200007;
int t[4*N],lc[4*N],rc[4*N],lazytag[4*N],
	v[N],fa[N],vt[N],at[N],size[N],son[N],top[N],dep[N],lcol,rcol,
	head[N],etot,atot,n,m;
struct node{
	int next,to;
}e[N];
void adde(int x,int y)
{
	e[++etot].next=head[x];
	e[etot].to=y;
	head[x]=etot;
}
void dfs1(int x,int f)
{
	fa[x]=f;dep[x]=dep[f]+1;
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
	at[x]=++atot;vt[atot]=v[x];
	top[x]=t;
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
		t[x]=1;lc[x]=rc[x]=vt[r];return;
	}
	int mid=l+(r-l>>1);
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	lc[x]=lc[x<<1];rc[x]=rc[x<<1|1];
	t[x]=t[x<<1]+t[x<<1|1];
	if(rc[x<<1]==lc[x<<1|1]) t[x]--;
}
void pushdown(int x,int l,int r)
{
	if(!lazytag[x]) return;
	int mid=l+(r-l>>1);
	lazytag[x<<1]=lazytag[x<<1|1]=t[x<<1]=t[x<<1|1]=1;
	lazytag[x]=0;
}
void change(int x,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		t[x]=1;lc[x]=rc[x]=v;lazytag[x]=1;
		return;
	}
	pushdown(x,l,r);
	int mid=l+(r-l>>1);
	if(mid>=ll) change(x<<1,l,mid,ll,rr,v);
	if(mid<rr) change(x<<1|1,mid+1,r,ll,rr,v);
	t[x]=t[x<<1]+t[x<<1|1];
	if(rc[x<<1]==lc[x<<1|1]) t[x]--;//如果有一边没有change，那是不是多减了 
}
int find(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return 0;
	if(l>=ll&&r<=rr) 
	{			printf("*");
		if(r==rr) rcol=rc[x];
		if(l==ll) lcol=lc[x];
		return t[x];
	}
	pushdown(x,l,r);
	int mid=l+(r-l>>1),res=0;
	if(mid>=ll) res+=find(x<<1,l,mid,ll,rr);
	if(mid<rr) res+=find(x<<1|1,mid+1,r,ll,rr);
	if(rc[x<<1]==lc[x<<1|1]) res--;
	return res;
}
int query(int x,int y)
{
	int xlast=-1,ylast=-1,ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		{
			swap(x,y);swap(xlast,ylast);
		}
		ans+=find(1,1,n,at[top[x]],at[x]);
		if(rcol==xlast) ans--;
		xlast=lcol;
		x=fa[top[x]];
		//	printf("ans=%d\n",ans);
	}
	if(x==y) return ans;
	if(dep[x]>dep[y])
	{
		swap(x,y);swap(xlast,ylast);
	} 
	ans+=find(1,1,n,at[x],at[y]);
	//	printf("ans=%d\n",ans);
	if(lcol==xlast) ans--;
	if(rcol==ylast) ans--;
	return ans;
}
void cr(int x,int y,int v)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		change(1,1,n,at[top[x]],at[x],v);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	change(1,1,n,at[x],at[y],v);
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,x,y,val;
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	}
	dfs1(1,0);dfs2(1,1);
	build(1,1,n);
	char c;
	for(i=1;i<=m;i++)
	{
		getchar();
		scanf("%c%d%d",&c,&x,&y);
		if(c=='C')
		{
			scanf("%d",&val);
			cr(x,y,val);
		}
		else
		{
			printf("%d\n",query(x,y));
		}
	}
	return 0;
}

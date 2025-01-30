#include<cstdio>
#include<algorithm>
using namespace std;
const int N=6000007; 
int at[N],fa[N],son[N],size[N],dep[N],top[N],head[N],t[4*N],lazytag[4*N],etot,atot,ans[N],a[N];
struct node{
	int next,to;
}e[N];
int n;
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
	top[x]=t;at[x]=++atot;
	if(!son[x]) return;
	dfs2(son[x],t);
	int i;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==fa[x]||e[i].to==son[x]) continue;
		dfs2(e[i].to,e[i].to);
	}
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
void change(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		lazytag[x]++;t[x]+=(r-l+1);
		return;
	}
	pushdown(x,l,r);
	int mid=l+(r-l>>1);
	if(mid>=ll) change(x<<1,l,mid,ll,rr);
	if(mid<rr) change(x<<1|1,mid+1,r,ll,rr);
	t[x]=t[x<<1]+t[x<<1|1];
}
void query(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		change(1,1,n,at[top[x]],at[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	change(1,1,n,at[x],at[y]);
}
int query2(int x,int l,int r,int tar)
{
	if(l==r&&r==tar)
		return t[x];
	if(l>tar||r<tar) return 0;
	int mid=l+(r-l>>1);
	pushdown(x,l,r);
	if(mid>=tar) return query2(x<<1,l,mid,tar);
	return query2(x<<1|1,mid+1,r,tar);
//	t[x]=t[x<<1]+t[x<<1|1];
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	} 
	dfs1(1,0);dfs2(1,1);
	
					//	for(i=1;i<=n;i++)
					///		printf("%d ",at[i]);
					//	printf("\n");
	for(i=2;i<=n;i++)
		query(at[a[i-1]],at[a[i]]);
	for(i=1;i<=n;i++)
		ans[i]=query2(1,1,n,at[i]);
	for(i=2;i<=n;i++)
		ans[a[i]]--;
	for(i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}

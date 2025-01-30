#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=300007;
int v[N],dep[N],cnt[N],fa[N][21],etot,qtot,size[N],n,m,depv[N],head[N];
struct node{
	int to,next,v;
}e[2*N];
struct node2{
	int x,y,lca,len;
}que[N]; 
bool comp(node2 x,node2 y)
{
	return x.len>y.len;
}
void adde(int x,int y,int v)
{
	e[++etot].next=head[x];
	e[etot].to=y;
	e[etot].v=v;
	head[x]=etot;
}
void addq(int x,int y,int v,int lca)
{
	que[++qtot].x=x;
	que[qtot].y=y;
	que[qtot].len=v;
	que[qtot].lca=lca;
}
void dfs1(int x,int f,int val)
{
	dep[x]=dep[f]+1;size[x]=1;
	fa[x][0]=f;v[x]=val;depv[x]=depv[f]+val;
	int i=0;
	for(i=1;i<=20;i++)
	{
		if(!fa[fa[x][i-1]][i-1]) break;
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs1(e[i].to,x,e[i].v);
		size[x]+=size[e[i].to];
	}
}
void dfs2(int x,int f)
{
	if(size[x]==1) return;
	int i;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs2(e[i].to,x);
		cnt[x]+=cnt[e[i].to];
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int i;
	for(i=20;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];y=fa[y][i];
		}
	return fa[x][0];
}
bool pd(int mid)
{
	memset(cnt,0,sizeof(cnt));
	int s=0,maxe=-1,i;
	while(que[++s].len>mid)
	{
		cnt[que[s].x]++;cnt[que[s].y]++;
		cnt[que[s].lca]-=2;
	}
	s--;
	dfs2(1,0);
	for(i=1;i<=n;i++)
		if(cnt[i]==s) maxe=max(maxe,v[i]);
	if(que[1].len-maxe>mid) return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,x,y,v,maxl=-1;
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		adde(x,y,v);adde(y,x,v);
	}
	dfs1(1,0,0);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		int z=lca(x,y);
		int len=depv[x]+depv[y]-2*depv[z];
		addq(x,y,len,z);
		maxl=max(maxl,len);
	}
	sort(que+1,que+1+n,comp);
	int l=0,r=maxl,mid,ans;
	while(l<=r)
	{
		mid=l+(r-l>>1);
		if(pd(mid))
		{
			r=mid-1;ans=mid;
		}
		else l=mid+1;
	}
	printf("%d",ans);return 0;
}

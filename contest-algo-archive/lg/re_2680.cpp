#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=300007;
int n,m,head[N],etot,t[N],fa[N][37],dep[N],depv[N],cnt,v[N];
struct edge{
	int next,to,v;
}e[N<<1];
struct wayn{
	int x,y,len,lca;
}way[N]; 
void adde(int x,int y,int v)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	e[etot].v=v;
	head[x]=etot;
}
void dfs1(int x,int f)
{
	dep[x]=dep[f]+1,fa[x][0]=f;
	for(int i=1;i<=30&&fa[fa[x][i-1]][i-1];i++) 	
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue; 
		depv[e[i].to]=depv[x]+e[i].v,v[e[i].to]=e[i].v;
		dfs1(e[i].to,x);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=30;i;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=30;i;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dfs2(int x,int f)
{
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs2(e[i].to,x);
		t[x]+=t[e[i].to];
	}
}
bool check(int x)
{
	memset(t,0,sizeof(t));int p=0,maxe=0;
	while(way[++p].len>x) t[way[p].x]++,t[way[p].y]++,t[way[p].lca]-=2;
	dfs2(1,0);
	for(int i=1;i<=n;i++) if(t[i]==p-1) maxe=max(maxe,v[i]);
	if(way[1].len-maxe>x) return 0;
	return 1;
	
 } 
bool cmp(wayn a,wayn b)
{
	return a.len>b.len;
}
int main()
{
	scanf("%d%d",&n,&m);
	int x,y,w,ans,Lca;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		adde(x,y,w);adde(y,x,w);
	}
	dfs1(1,0);
	for(int i=1;i<=m;i++) 
	{
		scanf("%d%d",&way[i].x,&way[i].y);
		Lca=lca(way[i].x,way[i].y);way[i].lca=Lca;
		way[i].len=depv[way[i].x]+depv[way[i].y]-2*depv[Lca];
	}
	sort(way+1,way+1+m,cmp);
	int l=0,r=way[1].len;
	while(l<=r) 
	{
		int mid=l+(r-l>>1);
		if(check(mid)) ans=mid,r=mid-1; 
		else l=mid+1;
	}
	printf("%d\n",ans);
		//for(int i=1;i<=n;i++) printf("%d ",depv[i]); printf("\n");
		//for(int i=1;i<=n;i++) printf("%d ",v[i]); printf("\n");
	return 0;
}

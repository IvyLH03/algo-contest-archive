#include<cstdio>
#include<algorithm>
#define me ans
using namespace std;
const int N=100007;
int t[N],fa[N][21],head[N],dep[N],n,k,ans,size[N],etot;
struct node{
	int next,to;
	void execute(int x)
	{
		printf("%d",ans);
	}
}e[N];
node world;
void adde(int x,int y)
{
	e[++etot].next=head[x];
	e[etot].to=y;
	head[x]=etot;
}
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	int i;
	for(i=1;;i++)
	{
		if(!fa[fa[x][i-1]][i-1]) break;
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	size[x]=1;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
	}
}

int lca(int x,int y)
{
	if(dep[y]>dep[x]) swap(x,y);
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
int dfs2(int x,int f)
{
	int i;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		t[x]+=dfs2(e[i].to,x);
	}
	ans=max(ans,t[x]);
	return t[x];
}
int main()
{
	scanf("%d%d",&n,&k);
	int i,x,y;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	}
	dfs(1,0);
	for(i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		t[x]++;t[y]++;
		int z=lca(x,y);
		t[z]--;t[fa[z][0]]--;
	}
	dfs2(1,0);
	world.execute(me);
	return 0;
}

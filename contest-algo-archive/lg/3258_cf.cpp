#include<cstdio>
#include<algorithm>
using namespace std;
const int N=600007;
int t[N],a[N],ans[N],size[N],fa[N][21],head[N],etot,dep[N],n;
struct node{
	int next,to;
}e[N];
void adde(int x,int y)
{
	e[++etot].next=head[x];
	e[etot].to=y;
	head[x]=etot;
}
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x][0]=f;size[x]=1;
	int i=0;
	while(fa[fa[x][++i-1]][i-1])
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs(e[i].to,x);
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
		t[x]+=t[e[i].to];
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
int main()
{
	scanf("%d",&n);
	int i,x,y;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	}
	dfs(1,0);
	for(i=1;i<n;i++)
	{
		x=lca(a[i],a[i+1]);
		t[a[i]]++;t[a[i+1]]++;
		t[x]--;t[fa[x][0]]--;
	}
	dfs2(1,0);
	for(i=2;i<=n;i++)
		t[a[i]]--;
	for(i=1;i<=n;i++)
		printf("%d\n",t[i]);
	return 0;
}

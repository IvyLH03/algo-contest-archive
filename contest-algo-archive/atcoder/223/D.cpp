#include<cstdio>
using namespace std;
const int N = 200007;
int n,m,head[N],d[N],etot;
bool vis[N];
struct edge
{
	int nxt,to;
}e[N];
void adde(int x,int y)
{
	e[++etot].to = y;
	e[etot].nxt = head[x];
	head[x] = etot;
}
bool dfs(int x)
{
	if(vis[x]) return 0;
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(!dfs(e[i].to)) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		d[y]++;
		adde(x,y);
	}
	for(int i=1;i<=n;i++)
		if((!vis[i])&&)
	for(int i=1;i<=n;i++)
		if(d[i]==0&&c[i])
		{
			q[++w]=i;vis[i]=1;break;
		}
	t=1;
	while(t<=w)
	{
		for(int i=head[q[t]];i;i=e[i].nxt) --d[e[i].to];
		for(int i=1;i<=n;i++) if(!(vis[i]||d[i])) q[++w]=i,vis[i]=1;
		t++;
	}
	for(int i=1;i<=n;i++) printf("%d ",q[i]);
	return 0;
	
}
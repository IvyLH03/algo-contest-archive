#include<cstdio>
#include<cstring>
using namespace std;
const int N=1007;
int l[N],head[N],etot,n,m,p;
bool vis[N];
struct edge{
	int next,to;
}e[1000007];
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	head[x]=etot;
}
bool dfs(int x)
{
	if(!x) return 1;
	for(int i=head[x];i;i=e[i].next)
	{
		if(!vis[e[i].to])
		{
			vis[e[i].to]=1;
			if(l[e[i].to]!=x&&dfs(l[e[i].to] 
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	int x,y;
	for(int i=1;i<=p;i++)
	{
		scanf("%d%d",&x,&y);
		if(x>n||y>m) continue;
		adde(x,y);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}

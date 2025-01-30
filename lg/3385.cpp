#include<cstdio>
#include<queue>
using namespace std;
const int N=100007,INF=1000000007;
struct edge{
	int next,to,v;
}e[N<<2];
int dis[N],head[N],etot,cnt[N],n,m,t;
bool vis[N];
queue<int>q;
void adde(int x,int y,int v)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	e[etot].v=v;
	head[x]=etot;
}
bool SPFA()
{
	for(int i=2;i<=n;i++) dis[i]=INF,cnt[i]=vis[i]=0;
	q.push(1);cnt[1]=1;dis[1]=0;
	while(!q.empty())
	{
		int p=q.front();q.pop();
		vis[p]=0;
		for(int i=head[p];i;i=e[i].next)
		{
			int u=e[i].to;
			if(dis[u]>dis[p]+e[i].v)
			{
				dis[u]=dis[p]+e[i].v;
				cnt[u]++;
				if(cnt[u]>n) return 1;
				if(!vis[u])
				{
					q.push(u);vis[u]=1;
				}
			 } 
		}
	}
	return 0;
}
int main()
{
	int t,x,y,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) head[i]=0;
		while(!q.empty()) q.pop();
		etot=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&v);
			adde(x,y,v);if(v>=0) adde(y,x,v);
		}
		if(SPFA()) printf("YE5\n");
		else printf("N0\n");
	}
	return 0;
}

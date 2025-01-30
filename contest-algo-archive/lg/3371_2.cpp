#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=500007,INF=2147483647;
int n,m,s,dis[N],head[N],etot;
bool vis[N];
struct edge{
	int next,to,v;
}e[N];
struct node{
	int pos,dis;
	friend bool operator <(const node x,const node y)
	{
		return x.dis>y.dis;
	}
};
void adde(int x,int y,int v)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	head[x]=etot;
	e[etot].v=v;
}
priority_queue<node>q;
void dijkstra()
{
	q.push((node){s,0});
	while(!(q.empty()))
	{
		int u=q.top().pos;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].v)
			{
				dis[v]=dis[u]+e[i].v;
				if(!vis[v]) q.push((node){v,dis[v]});
				
			}
		}
		
	}
 } 
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	int x,y,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		adde(x,y,v);
	}
	int i=head[s];
	for(int i=1;i<=n;i++)
		if(i!=s) dis[i]=INF;
	dijkstra();
	for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	return 0;
}

#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=10007,M=200007,INF=1000000000;
int head[N],head2[N],etot,e2tot,n,m,s,t,dis[N];
bool ist[N],isr[N],vis[N];
struct edge{
	int next,to;
}e[M],e2[M];
struct node{
	int pos,dis;
	friend bool operator < (node x,node y)
	{
		return x.dis>y.dis;
	 } 
};
priority_queue<node>q;
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	head[x]=etot;
 } 
void adde2(int x,int y)
{
	e2[++e2tot].to=y;
	e2[e2tot].next=head2[x];
	head2[x]=e2tot;
}
void bfs()
{
	queue<int>q;q.push(t);
	while(!q.empty())
	{
		int ed=q.front();q.pop();
		for(int i=head2[ed];i;i=e2[i].next)
		{
			int v=e2[i].to;
			if(!ist[v]) q.push(v);ist[v]=1;
		 } 
	}
}
void pre()
{
	for(int i=1;i<=n;i++)
	{	
		if(!ist[i]) continue; 
		bool flag=0;
		for(int j=head[i];j;j=e[j].next)
		{
			if(!ist[e[j].to]) flag=1;
		}
		if(!flag) isr[i]=1;
	}
}
void dijkstra()
{
	for(int i=1;i<=n;i++) dis[i]=INF,vis[i]=0;
	if(!isr[s]) return;
	dis[s]=0;
	q.push((node){s,0});
	while(!q.empty())
	{
		node ed=q.top();q.pop();
		if(vis[ed.pos]) continue;
		vis[ed.pos]=1;
		for(int i=head[ed.pos];i;i=e[i].next)
		{
			if(isr[e[i].to]&&dis[e[i].to]>dis[ed.pos]+1)
			{
				dis[e[i].to]=dis[ed.pos]+1;
				if(!vis[e[i].to]) q.push((node){e[i].to,dis[e[i].to]});
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde2(y,x);
	}
	scanf("%d%d",&s,&t);
	bfs();
	ist[t]=1;
	pre();
	isr[t]=1;
	dijkstra();
	if(dis[t]==INF) printf("-1");
	else printf("%d",dis[t]);
	return 0;
}

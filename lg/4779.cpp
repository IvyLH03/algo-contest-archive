#include<cstdio>
#include<algorithm>
#include<queue> 
using namespace std;
const int N=200007,INF=2147483647;
struct node{
	int pos,dis;
	friend bool operator <(const node x,const node y)
	{
		return x.dis>y.dis;
	}
};
struct edge{
	int to,next,v;
}e[N<<1];
int n,m,s,dis[N],head[N],etot;
bool vis[N];
priority_queue<node>q;
void adde(int x,int y,int v)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	e[etot].v=v;
	head[x]=etot;
}
void dijkstra()
{
	q.push((node){s,0});
	while(!q.empty())
	{
		node ed=q.top();q.pop();
		if(vis[ed.pos]) continue;
		vis[ed.pos]=1;
		for(int i=head[ed.pos];i;i=e[i].next)
		{
			if(dis[e[i].to]>dis[ed.pos]+e[i].v)
			{
				dis[e[i].to]=dis[ed.pos]+e[i].v;
				if(!vis[e[i].to]) q.push((node){e[i].to,dis[e[i].to]});
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
		adde(x,y,v);adde(y,x,v);
	}
	for(int i=1;i<=n;i++) if(i!=s) dis[i]=INF;
	dijkstra();
	for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	return 0;
}

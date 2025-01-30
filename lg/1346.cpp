#include<cstdio>
#include<queue>
using namespace std;
const int N=200007,INF=1000000007;
int head[N],etot,n,s,t,dis[N];
bool vis[N];
struct edge{
	int next,to,w;
}e[N];
struct node{
	int pos,dis;
	friend bool operator <(node x,node y)
	{
		return x.dis>y.dis; 
	}
};
void adde(int x,int  y,int w)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	e[etot].w=w;
	head[x]=etot;
}
priority_queue<node>q;
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
			if(dis[e[i].to]>dis[ed.pos]+e[i].w)
			{
				dis[e[i].to]=dis[ed.pos]+e[i].w;
				if(!vis[e[i].to]) q.push((node){e[i].to,dis[e[i].to]});
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&s,&t);
	int x,y,k;
	for(int i=1;i<=n;i++) dis[i]=INF;
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(!k) continue;
		scanf("%d",&y);
		adde(i,y,0);//adde(y,i,0);
		for(int j=1;j<k;j++)
		{
			scanf("%d",&y);
			adde(i,y,1);//adde(y,i,1);
		}
	}
	dijkstra();
	if(dis[t]==INF) printf("-1");
	else printf("%d",dis[t]);
	return 0;
}

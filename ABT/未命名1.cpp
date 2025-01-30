#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N=2007;
const long long INF=100000000000000;
struct egde{
	long long next,to,v;
}e[N],e2[N];
struct node{
	long long pos,dis;
	friend bool operator <(const node x,const node y)
	{
		return x.dis>y.dis;
	}
};
priority_queue<node>q;
int n,m,k,s,t,head[N],etot;
long long dis[N],ans;
bool vis[N];
void adde(int x,int y,int v)
{
	e2[++etot].to=y;
	e2[etot].v=v;
	e2[etot].next=head[x];
	head[x]=etot;
}
long long dijkstra()
{
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		if(i!=s) dis[i]=INF;
	}
	q.push((node){s,0});
	while(!q.empty())
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
	return dis[t];
}
int main()
{
	ans=INF;int x,y,v;
	scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		adde(x,y,v);
	}
	memcpy(e,e2,sizeof(e2));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++) e[j].v=max(e2[j].v-e2[i].v,(long long)0);
		ans=min(ans,dijkstra()+e2[i].v*k);
	}
	printf("%lld",ans);
	return 0;
}

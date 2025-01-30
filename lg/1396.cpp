#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=20007,INF=1000000007;
int n,m,head[N],etot,dis[N],s,t;
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
priority_queue<node>q;
void adde(int x,int y,int w)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	e[etot].w=w;
	head[x]=etot;
}

void dijkstra(int x)
{
	q.push((node){s,0});
	while(!q.empty())
	{
		node ed=q.top();q.pop();
		if(vis[ed.pos]) continue;
		vis[ed.pos]=1;
		for(int i=head[ed.pos];i;i=e[i].next)
		{
			if(e[i].w>x) continue;
			if(dis[e[i].to]>dis[ed.pos]+e[i].w)
			{
				dis[e[i].to]=dis[ed.pos]+e[i].w;
				if(!vis[e[i].to]) q.push((node){e[i].to,dis[e[i].to]});
			}
		 } 
	}
}
bool pd(int x)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=INF;head[i]=vis[i]=0;
	}
	dis[s]=0;etot=0;
	dijkstra(x);
	printf("dis[t]=%d\n",dis[t]);
	if(dis[t]!=INF) return 1;
	return 0;
}
bool comp(edge x,edge y)
{
	return x.w<y.w;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	int l=1,r=0,ans=-1,x,y,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		r=max(r,w);
		adde(x,y,w);adde(y,x,w);
	}
	while(l<=r)
	{
		int mid=l+(r-l>>1);
		if(pd(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}

#include<cstdio>
#include<queue>
using namespace std;
const int N=2000007,mod=100003,INF=1000000007;
int n,m,head[N],etot,dis[N],ans[N],cnt[N];
bool vis[N];
struct edge{
	int next,to;
}e[N];
struct node{
	int pos,dis;
	friend bool operator <(node x,node y)
	{
		return x.dis>y.dis;
	}
};
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	head[x]=etot;
}
priority_queue<node>q;
void dijkstra()
{
	q.push((node){1,0});cnt[1]=1;
	while(!q.empty())
	{
		node ed=q.top();q.pop();
		if(vis[ed.pos]) continue;
		vis[ed.pos]=1;
		for(int i=head[ed.pos];i;i=e[i].next)
		{
			if(dis[e[i].to]==dis[ed.pos]+1) cnt[e[i].to]+=cnt[ed.pos],cnt[e[i].to]%=mod;
			else if(dis[e[i].to]>dis[ed.pos]+1)
			{
				cnt[e[i].to]=cnt[ed.pos]%mod;dis[e[i].to]=dis[ed.pos]+1;
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
		scanf("%d%d",&x,&y);adde(x,y);adde(y,x);
	}
	for(int i=1;i<=n;i++) dis[i]=INF;
	dis[1]=0;
	dijkstra();
	for(int i=1;i<=n;i++) printf("%d\n",cnt[i]%mod);
	return 0;
}

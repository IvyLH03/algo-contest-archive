#include<cstdio>
#include<queue>
using namespace std;
const int N=200007;
struct edge{
	int nxt,to;
}e[N<<1];
struct node{
	int pos,dis;
	friend bool operator < (node x,node y)
	{
		return x.dis>y.dis;
	}
}; 
int n,m,qt,head[N],etot,dis[N][2];
bool vis[N];
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].nxt=head[x];
	head[x]=etot;
}
priority_queue<node>q;
void dijkstra()
{
	for(int i=1;i<=n;i++) dis[i][0]=dis[i][1]=N;
	for(int i=head[1];i;i=e[i].nxt)
	{
		dis[e[i].to][1]=1;
		q.push((node){e[i].to,1});
	}
	while(!q.empty())
	{
		node u=q.top();q.pop();
	//	if(vis[u.pos]) continue;
	//	vis[u.pos]=1;
		for(int i=head[u.pos];i;i=e[i].nxt)
		{
			if(dis[e[i].to][(u.dis+1)%2]>u.dis+1)
			{
				dis[e[i].to][(u.dis+1)%2]=u.dis+1;
				if(!vis[e[i].to]) q.push((node){e[i].to,u.dis+1});
			}
		} 
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&qt);int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	}
	dijkstra();
	while(qt--)
	{
		scanf("%d%d",&x,&y);
		if(dis[x][y%2]<y) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

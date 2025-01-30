#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=50007;
struct edge{
	int next,to,w;
}e[N<<1];
long long head[N],etot,n,m,dis[N],b;
int f[N];
bool vis[N];
void adde(int x,int y,int w)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	e[etot].w=w;
	head[x]=etot;
}
struct node{
	int pos,dis;
	friend bool operator <(node x,node y)
	{
		return x.dis>y.dis;
	}
};
priority_queue<node>q;
long long dijkstra(int x)
{
	for(int i=1;i<=n;i++) vis[i]=0,dis[i]=-1;
	q.push((node){1,0});
	while(!q.empty())
	{
		node ed=q.top();q.pop();
		if(vis[ed.pos]) continue;
		vis[ed.pos]=1;
		for(int i=head[ed.pos];i;i=e[i].next)
		{
			if(f[e[i].to]>x) continue;
			if(dis[ed.pos]+e[i].w<dis[e[i].to]||dis[e[i].to]==-1)
			{
				dis[e[i].to]=dis[ed.pos]+e[i].w;
				if(!vis[e[i].to]) q.push((node){e[i].to,dis[e[i].to]});
			}
		}
	}
	return dis[n];
}
bool pd(int x)
{
	long long s=dijkstra(x);
//	printf("s=%d\n",s);
	if(s==-1||s>b) return 0;
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&b);
	int x,y,l=1,r=0,w,ans=-1;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&f[i]);
		r=max(r,f[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		adde(x,y,w);adde(y,x,w);
	}
	while(l<=r)
	{
		int mid=l+(r-l>>1);
		if(pd(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(ans==-1) printf("AFK");
	else printf("%d",ans);
}

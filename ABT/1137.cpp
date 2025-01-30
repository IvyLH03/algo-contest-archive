#include<cstdio>
#include<queue>
using namespace std;
const int N=1e6+7;
int n,m,head[4*N],num,e[4*N],dis[4*N];
struct node{
	int to,next;
}a[N];
queue<int>q;
void add(int x,int y)
{
	a[++num].to=head[x];
	a[num].next=y;e[y]++;
	head[x]=num;
}
int main()
{
	int i,s,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(i=1;i<=n;i++)
	{
		if(!e[i])
		{
			q.push(i);dis[i]=1;
		}
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		i=head[x];
		while(i)
		{
			e[a[i].next]--;
			if(!e[a[i].next])
			{
				q.push(a[i].next);dis[a[i].next]=dis[x]+1;
			}
			i=a[i].to;
		}
	}
	for(i=1;i<=n;i++)
		printf("%d\n",dis[i]);
	return 0;
}

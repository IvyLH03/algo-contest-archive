#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50007;
int dfn[N],low[N],stack[N],etot,ltot,head[N],dtot,top,cnt[N],d[N],n,m,num[N],cd[N];
bool vis[N];
struct node{
	int to,next;
}e[N];
void add(int x,int y)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	head[x]=etot;
}
void tarjan(int u)
{						
	dfn[u]=low[u]=++ltot;
	stack[++top]=u;
	int i;
	for(i=head[u];i;i=e[i].next)
	{		
		int v=e[i].to;
		if(!dfn[v])
		{
			vis[v]=1;tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!d[v]) low[u]=min(low[u],low[v]);
	}
	if(low[u]==dfn[u]) 
	{
		cnt[++dtot]++;
		d[u]=dtot;
		while(stack[top]!=u)
		{
			d[stack[top]]=dtot;
			top--;cnt[dtot]++;
		}
		top--;
	}
	
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,x,y;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
	} 
	for(i=1;i<=n;i++)
		if(!dfn[i])	tarjan(i);
	for(i=1;i<=n;i++)
	{
		for(int j=head[i];j;j=e[j].next)
			if(d[e[j].to]!=d[i]) cd[d[i]]++;
	}
					//	for(i=1;i<=n;i++)
					//		printf("cd[d[%d]]=%d\n",i,cd[d[i]])	;
	int flag=0,ans;
	for(i=1;i<=dtot;i++)
		if(!cd[i])
		{
			if(flag) 
			{
				printf("0");return 0;
			}
			ans=cnt[i];flag=1;
		}
	printf("%d",ans);
	return 0;
}

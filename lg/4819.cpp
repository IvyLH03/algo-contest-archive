#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300007;
int dfn[N],low[N],d[N],dtot,etot,ltot,head[N],stack[N],top,in[N],cnt[N],head2[N],e2tot;
struct node{
	int to,next;
}e[N],e2[N];
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
	in[y]++;
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
			tarjan(v);low[u]=min(low[u],low[v]);
		}
		else if(!d[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u])
	{
		d[u]=++dtot;cnt[dtot]++;
		while(stack[top]!=u)
		{
			cnt[dtot]++;
			d[stack[top]]=dtot;
			top--;
		}
		top--;
	}
}
int main()
{
	int n,m,x,y,i,j;
	double r;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);
	}
	for(i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	for(i=1;i<=n;i++)
	{
		for(j=head[i];j;j=e[j].next)
		{
			int v=e[j].to;
			if(d[v]!=d[i]) adde2(d[i],d[v]);
		}
	}
	bool flag=0;int tot=0;
	for(i=1;i<=dtot;i++)
	{
		if(!in[i]) 
		{
			tot++;
			if(cnt[i]==1)
			{
				flag=1;
				for(j=head2[i];j;j=e2[j].next)
					if(in[e2[j].to]==1)
					{
						flag=0;break;
					}
			}
		}
	}
	if(flag) tot--;
	r=1.0*(n-tot)/n;
	printf("%.6lf",r);
	return 0;
}

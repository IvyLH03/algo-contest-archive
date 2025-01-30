#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10007;
int a[N],dfn[N],low[N],d[N],stack[N],in[N],top,e1tot,e2tot,ltot,
	dtot,head1[N],head2[N],v[N],n,m,tp[N],f[N];
struct node{
	int to,next;
}e1[N],e2[N];
void adde1(int x,int y)
{
	e1[++e1tot].to=y;
	e1[e1tot].next=head1[x];
	head1[x]=e1tot;
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
	for(i=head1[u];i;i=e1[i].next)
	{
		int v=e1[i].to;
		if(!dfn[v])
		{
			tarjan(v);low[u]=min(low[u],low[v]);
		}
		else if(!d[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u])
	{
		d[u]=++dtot;
		v[dtot]+=a[u];
		while(stack[top]!=u)
		{
			d[stack[top]]=dtot;
			v[dtot]+=a[stack[top]];
			top--;
		}
		top--;
	}
}
void topo()
{
	int t=1,w=0,ans=-1,i;
	for(i=1;i<=dtot;i++)
	{
		if(!in[i]) tp[++w]=i;
		f[i]=v[i];
	}
	while(t<=w)
	{			
		for(i=head2[tp[t]];i;i=e2[i].next)
		{
			in[e2[i].to]--;					
			f[e2[i].to]=max(f[e2[i].to],f[tp[t]]+v[e2[i].to]);
				//	printf("f[e2[i].to]=%d,f[tp[t]]+v[e2[i].to]=%d\n",f[e2[i].to],f[tp[t]]+v[e2[i].to]);
			if(!in[e2[i].to]) tp[++w]=e2[i].to;
		}
		t++;
	}
	for(i=1;i<=dtot;i++)
	{
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j,x,y;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		adde1(x,y);
	}
	for(i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	for(i=1;i<=n;i++)
	{
		for(j=head1[i];j;j=e1[j].next)
		{
			int v=e1[j].to;
			if(d[v]!=d[i]) adde2(d[i],d[v]);
		}
	}
	topo();
	return 0;
}

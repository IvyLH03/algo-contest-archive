#include<cstdio>
using namespace std;
const int N=107;
int c[N],u[N],q[N],d[N],etot,n,m,ch[N],head[N];
struct edge
{
	int nxt,to,v;
}e[1000007];
void adde(int x,int y,int v)
{
	e[++etot].to=y;
	e[etot].nxt=head[x];
	e[etot].v=v;
	d[y]++;ch[x]++;
	head[x]=etot;
}
void tpsort()
{
	int t=1,w=0;
	for(int i=1;i<=n;i++)
	{
		if(!d[i]) q[++w]=i;
	}
	while(t<=w)
	{
		for(int i=head[q[t]];i;i=e[i].nxt)
		{
			d[e[i].to]--;
			if(!d[e[i].to]) q[++w]=e[i].to;
		}
		t++;
	}
}
int main()
{
	scanf("%d%d",&n,&m);int x,y,v;
	for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&u[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		adde(x,y,v);
	}
	for(int i=1;i<=n;i++) if(d[i]) c[i]-=u[i];
	tpsort();
	for(int i=1;i<=n;i++)
	{
		if(c[q[i]]<=0) continue; 
		for(int j=head[q[i]];j;j=e[j].nxt)
		{
			c[e[j].to]+=e[j].v*c[q[i]];
		}
	}
	bool flag=0;
	for(int i=1;i<=n;i++)
		if(ch[i]==0&&c[i]>0) 
		{
			flag=1;printf("%d %d\n",i,c[i]);
		}
	if(!flag) printf("NULL");
	return 0;
}

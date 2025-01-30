#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200000;
int n,head[N],etot,w[N],f[N],maxa,tota;
struct edge
{
	int nxt,to;
 }e[N<<1];
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].nxt=head[x];
	head[x]=etot;
}
void dfs(int x,int f)
{
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==f) continue;
		dfs(e[i].to,x);
	}
	int max1=0,max2=0,tot=0;
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==f) continue;
		if(f) maxa=max(maxa,w[f]*w[e[i].to]);
		tot+=w[e[i].to];
		if(w[e[i].to]>max1) max2=max1,max1=w[e[i].to];
		else if(w[e[i].to]>max2) max2=w[e[i].to];
	}
	if(f)
	{
		
		tota+=tot*w[f];
		maxa=max(maxa,max1*w[f]);
	}
	if(max1&&max2)
	{
		maxa=max(maxa,max1*max2);
		for(int i=head[x];i;i=e[i].nxt)
		{
			if(e[i].to==f) continue;
			tot-=w[e[i].to];
			tota+=w[e[i].to]*tot;
		}
	}
	
}
int main()
{
	scanf("%d",&n);int x,y;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	}
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	dfs(1,0);
	printf("%d %d",maxa,tota*2%10007);
}

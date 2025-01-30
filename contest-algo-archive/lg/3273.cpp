#include<cstdio>
#include<algorithm> 					//并查集模拟加链，拓扑排序（不会链表自己想的），然后跑线段树 
#include<queue>
using namespace std;
const int N=300007;
int fa[2*N],v[2*N],L[2*N],R[2*N],head[2*N],atot,n,m,qftot,qatot,ttot,e[2*N],tp[2*N];
queue<int>q;
struct qf{
	int type,x;
}qf[2*N];
struct qa{
	int type,x,val;
}qa[2*N];
struct node{
	int next,to;
}a[2*N];
int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]==find(fa[x]);
	return fa[x];
}
void unionn(int x,int y)
{
	x=find(x);y=find(y);
	if(x==y) return;
	if(x<y) swap(x,y);
	fa[y]=x;
}
void adda(int x,int y)
{
	a[++atot].next=head[x];
	a[atot].to=y;
	head[x]=atot;
}
void topo()
{							
	int i,p;
	for(i=1;i<=n;i++)
	{						
		if(e[i]==0) q.push(i);tp[++ttot]=i;
	}
	while(!q.empty())
	{					//	printf("*");
		p=q.front();
		q.pop();
		i=head[p];
		while(i)
		{
			e[a[i].to]--;
			if(!e[a[i].to])
			{
				q.push(a[i].to);
				tp[++ttot]=a[i].to;
			}
			i=a[i].next;
		}
	}
}
int main()
{
	int i,j,k,x,y,z;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	scanf("%d",&m);
	char c;
	for(i=1;i<=m;i++)
	{
		getchar();											//提交的时候似乎要用两个getchar 
		scanf("%c",&c);
		if(c=='U')
		{					//		printf("*");
			scanf("%d%d",&x,&y);
			unionn(x,y);
			adda(x,y);
		}
		if(c=='A')
		{
			scanf("%d",&qa[++qatot].type);					//这种存问题的方式有很大问题（不能保证A和F的顺序） 
			if(qa[qatot].type==3) scanf("%d",&qa[qatot].val);
			else scanf("%d%d",&qa[qatot].x,&qa[qatot].val);
		}
		if(c=='F')
		{
			scanf("%d",&qf[++qftot].type);
			if(qf[qftot].type!=3) scanf("%d",&qf[qftot].x);
		}
	}
	topo();
									for(i=1;i<=n;i++)
									{
										printf("%d ",tp[i]);
									}
	return 0;
}



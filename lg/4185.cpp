#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100007;
struct edge{
	int x,y,v;
}e[N];
struct node{
	int k,u,num;
}q[N];
int n,m,fa[N],siz[N],ans[N];
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int x,int y)
{
	siz[find(y)]+=siz[find(x)];siz[find(x)]=0;
	fa[find(x)]=find(y);
}
bool cmp1(edge x,edge y)
{
	return x.v>y.v;
}
bool cmp2(node x,node y)
{
	return x.k>y.k;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)  scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
	for(int i=1;i<=m;i++) 
	{
		scanf("%d%d",&q[i].k,&q[i].u);q[i].num=i;
	}
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	sort(e+1,e+n,cmp1);sort(q+1,q+1+m,cmp2);int p=1;
	for(int i=1;i<=m;i++)
	{
		while(e[p].v>=q[i].k&&p<=m) 
		{
			if(find(e[p].x)!=find(e[p].y)) unionn(e[p].x,e[p].y);
			p++;
		}
		ans[q[i].num]=siz[find(q[i].u)]-1;
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}

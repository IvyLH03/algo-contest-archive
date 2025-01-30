#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200000;
struct node{
	int x,y,len;
}a[2*N]; 
int fa[2*N],ans,n,m,tot;
bool vis[2*N];
int find(int x)
{
	if(fa[x]==x)	return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int x,int y)
{
	x=find(x);y=find(y);
	fa[y]=x;
}
bool comp(node x,node y)
{
	return x.len<y.len;
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].len);
	sort(a+1,a+1+m,comp);
	tot=0;
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=m;i++)
	{
		if(find(a[i].x)==find(a[i].y)) continue;
		ans+=a[i].len;unionn(a[i].x,a[i].y);
		if(++tot==n-1) break;
	}
	printf("%d",ans);
	return 0;
}



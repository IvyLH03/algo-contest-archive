#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2*10e5;
int father[N],b[N],n,ans,m;
struct node{
	int x,y,c;
}a[N];
bool comp(node x,node y)
{
	return x.c>y.c;
}
int find(int x)
{
	if(father[x]==x) return x;
	father[x]=find(father[x]);
	return father[x];
}
void unionn(int x,int y)
{
	father[find(y)]=find(x);
}
int main()
{
	int i,j,k;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
	sort(a+1,a+1+n,comp);
	for(i=1;i<=m;i++)
		father[i]=i;
	for(i=1;i<=n;i++)
	{
		if(find(a[i].x)==find(a[i].y))
		{
			ans=a[i].c;break;
		}
		if(!b[a[i].x]) b[a[i].x]=a[i].y;
		else unionn(b[a[i].x],a[i].y);
		if(!b[a[i].y]) b[a[i].y]=a[i].x;
		else unionn(b[a[i].y],a[i].x);
	}
	printf("%d",ans);
	return 0;
}


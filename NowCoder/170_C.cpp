#include<cstdio>
using namespace std;
int n,k,m,father[10001],a[10001][6];
int find(int x)
{
	if(father[x]!=x) return find(father[x]);
	return x;
}
void unionn(int a,int b)
{
	father[a]=b;
}
int search(int a)
{
	
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int i,j,k,a,b,r1,r2,t;
	for(i=1;i<=n;i++)
	{
		father[i]=i;
		for(j=1;j<=k;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=1;i<=k;i++)
	{
		scanf("%d%d%d",&t);
		if(t==1)
		{
			scanf("%d%d",&a,&b);
			r1=find(a);r2=find(b);
			unionn(r1,r2);
		}
		if(t==2)
		{
			scanf("%d",&a);
			b=search(find(a));
			printf("%d\n",b);
		}
	}
	return 0;
}

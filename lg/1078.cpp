#include<cstdio>
#include<algorithm>
using namespace std;
int f[101][101],c[101];
bool a[101][101];
int main()
{
	int n,k,m,s,t,i,j,u,v,d;
	scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=k;j++)
			scanf("%d",&a[i][j]);
		a[i][i]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			f[i][j]=1000000;
		f[i][i]=0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&d);
		f[u][v]=min(f[u][v],d);
	}
	
	
} 

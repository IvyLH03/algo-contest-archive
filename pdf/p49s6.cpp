#include<cstdio>
using namespace std;
int a[101][101],b[101][101],c[101][101];
int main()
{
	int i,j,n,m,aa=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			c[i][j]=a[i][j];
		}
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&b[i][j]);
			c[i][j]+=b[i][j];
		}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			printf("%d ",c[i][j]);		
		printf("\n");

	}
	return 0;		
}

#include<cstdio>
using namespace std;
int a[101][101];
int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	
	for(i=1;i<=m;i++)
	{
		for(j=n;j>=1;j--)
			printf("%d ",a[j][i]);
		printf("\n");
	}
	return 0;
} 

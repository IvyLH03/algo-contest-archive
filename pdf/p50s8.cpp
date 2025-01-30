#include<cstdio>
using namespace std;
int a[101][101];
int main()
{
	int i,j,m,n;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",a[j][i]);
		printf("\n");
	}
	
	return 0;
}

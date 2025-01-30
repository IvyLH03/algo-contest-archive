#include<cstdio>
using namespace std;
const int n=6;
int a[n+1][n+1];
int main()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j||i+j==7) a[i][j]+=10;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;	
}


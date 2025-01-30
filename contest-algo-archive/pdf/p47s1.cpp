#include<cstdio>
using namespace std;
int a[6][6],temp;
int main()
{
	int m,n,i,j;
	for(i=1;i<=5;i++)
		for(j=1;j<=5;j++)
			scanf("%d",&a[i][j]);
	
	scanf("%d%d",&m,&n);
	
	for(i=1;i<=5;i++)
	{
		temp=a[m][i];a[m][i]=a[n][i];a[n][i]=temp;
	}
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}

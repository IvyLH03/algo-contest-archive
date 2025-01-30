#include<cstdio>
using namespace std;
int main()
{
	int a[11][11]={},i,j;
	a[1][1]=1;
	for(i=2;i<=10;i++)
	{
		a[i][1]=1;a[i][i]=1;
		for(j=1;j<=i;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
	}
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10-i;j++) printf(" ");
		for(j=1;j<=i;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
	
	return 0;
}

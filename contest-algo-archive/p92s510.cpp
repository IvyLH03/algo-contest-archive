#include<cstdio>
using namespace std;
const int n=3,m=5;
int main()
{
	int a[n+1][m+1],b[101][4],k=0,i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)
			{
				k++;b[k][1]=i;b[k][2]=j;b[k][3]=a[i][j];
			}
		}
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=3;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	return 0;
}

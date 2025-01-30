#include<cstdio>
using namespace std;
int a[101][101],b[101][101],c[101][101];
int main()
{
	int n,m,k,i,j,kk;
	scanf("%d%d%d",&n,&m,&k);
	
	for(i=1;i<=n;i++)//A
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	
	for(i=1;i<=m;i++)//B
		for(j=1;j<=k;j++)
			scanf("%d",&b[i][j]);
	
	for(i=1;i<=n;i++)//C
		{
			for(j=1;j<=k;j++)
			{
				for(kk=1;kk<=m;kk++)
					{
						c[i][j]+=(a[i][kk]*b[kk][j]);

					}
				printf("%d ",c[i][j]);
			}
			printf("\n");
		}
	return 0;
}

#include<cstdio>
using namespace std;
int a[801][801],f[801][801][20][2],n,m,mk,ans;
int main()
{
	int i,j,k;
	scanf("%d%d%d",&n,&m,&mk);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			f[i][j][a[i][j]][0]=1;
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			for(k=0;k<=mk;k++)
			{
			
			//	f[i][j][k][1]=f[i][j][k][1]+f[i-1][j][mk+k-a[i][j]][0]+f[i][j-1][mk+k-a[i][j]][0];
				f[i][j][k][1]=(f[i][j][k][1]+f[i-1][j][(k+a[i][j]+mk+1)%(mk+1)][0]+f[i][j-1][(k+a[i][j]+mk+1)%(mk+1)][0])%1000000007;
		//	}
		//	for(k=a[i][j];k<=mk;k++)
		//	{
				f[i][j][k][0]=(f[i][j][k][0]+f[i-1][j][(k-a[i][j]+mk+1)%(mk+1)][1]+f[i][j-1][(k-a[i][j]+mk+1)%(mk+1)][1])%1000000007;
				//f[i][j][k][0]=f[i][j][k][0]+f[i-1][j][mk+k-a[i][j]][1]+f[i][j-1][mk+k-a[i][j]][1];
			}
		}
	ans=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			ans=(ans+f[i][j][0][1])%1000000007;
			
	printf("%d",ans);
	return 0;
}

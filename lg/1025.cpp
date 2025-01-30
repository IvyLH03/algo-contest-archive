#include<cstdio>
using namespace std;
int n,k,tot,a[201][7];
int main()
{
	scanf("%d",&n,&k);
	
	int i,j;
	for(i=1;i<=n;i++)
	{
		a[i][0]=0;
		a[i][1]=1;
	}
	for(i=2;i<=n;i++)
	{
		a[0][i]=0;
		a[1][i]=0;
	}
	
	for(i=1;i<=n;i++)
		for(j=1;j<=k;j++)
			a[i][j]=a[i-1][j-1]+1;
		
	printf("%d",tot);
	return 0;
}

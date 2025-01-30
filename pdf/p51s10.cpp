#include<cstdio>
using namespace std;
int a[101][101],b[101][101];
int main()
{
	int m,n,i,k,j;
	scanf("%d%d",&m,&n);
	
	for(i=1;i<=m;i++)
		for(k=1;k<=n;k++)
			scanf("%d",&a[i][k]);
			
	for(i=1;i<=m;i++)	
		for(k=1;k<=n;k++)
			if((i==1||i==m)||(k==1||k==n))
				b[i][k]=a[i][k];
			else
				b[i][k]=(a[i][k]+a[i][k+1]+a[i][k-1]+a[i+1][k]+a[i-1][k])/5;
	
	for(i=1;i<=m;i++)
	{
		for(k=1;k<=n;k++)
			printf("%d ",b[i][k]);
		printf("\n");
	}
			
		
		
	return 0;
}

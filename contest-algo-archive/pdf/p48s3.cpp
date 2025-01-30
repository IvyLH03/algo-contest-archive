#include<cstdio>
using namespace std;
int a[101][101];
int main()
{
	int m,n,i,j,s=0;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			{
				if(i==1||i==m) s+=a[i][j];
				else if(j==1||j==n) s+=a[i][j];
			}
	printf("%d",s);
	return 0;
}

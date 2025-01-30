#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1005;
int a[maxn][maxn],f[maxn][maxn],n;
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		f[n][i]=a[n][i];
	for(i=n-1;i>=1;i--)
		for(j=1;j<=i;j++)
			f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
			
	printf("%d",f[1][1]);
	return 0;
}

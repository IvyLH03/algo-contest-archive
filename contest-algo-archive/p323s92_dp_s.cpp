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
	f[1][1]=a[1][1];
	for(i=2;i<=n;i++)
		for(j=1;j<=i;j++)
			f[i][j]=max(f[i-1][j],f[i-1][j-1])+a[i][j];
	int ans=f[n][1];
	for(i=2;i<=n;i++)
		ans=max(ans,f[n][i]);
	printf("%d",ans);
	return 0;
	
}

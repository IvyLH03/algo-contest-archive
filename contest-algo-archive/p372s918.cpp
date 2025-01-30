#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[101][101],s[101],n,i,j,k,x;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s[i]=s[i-1]+x;
	}
	memset(f,127/3,sizeof(f));
	for(i=1;i<=n;i++)
		f[i][i]=0;
	for(i=n-1;i>=1;i--)
		for(j=i+1;j<=n;j++)
			for(k=1;k<=j-1;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
	printf("%d",f[1][n]);
	return 0;
} 

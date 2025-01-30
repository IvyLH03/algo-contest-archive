#include<cstdio>
#include<cstring>
using namespace std;
int n,f[107][107],s[107];
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int i,j,k;
	scanf("%d",&n);
	
	memset(f,1,sizeof(f)); 
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		f[i][i]=0;
		s[i]=s[i-1]+k;
	}	
	
	for(i=n-1;i>=1;i--)
	{
		for(j=i+1;j<=n;j++)
		{
			for(k=i;k<=j-1;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
		}
	}
	
	printf("%d",f[1][n]);
	return 0;
}

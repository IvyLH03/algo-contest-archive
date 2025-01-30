#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,s[207],f[207][207],d[207][207];
int main()
{
	memset(f,127/3,sizeof(f));
	
	int i,j,k;
	scanf("%d",&n);
				
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		s[i]=s[i+n]=s[i-1]+k;
		f[i][i]=f[i+n][i+n]=0;
	}
	
	for(i=n+1;i<=2*n;i++)
		s[i]+=s[n];
							//	for(i=1;i<=2*n;i++)
							//		printf("%d ",s[i]);	
						
	for(i=2*n-1;i>=1;i--)
	{
		for(j=i+1;j<=2*n;j++)
			for(k=i;k<=j-1;k++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
				d[i][j]=max(d[i][j],d[i][k]+d[k+1][j]+s[j]-s[i-1]);
			}
	}
	
	int ansmin=100000001,ansmax=0;
	for(i=1;i<=n;i++)
	{
		ansmin=min(ansmin,f[i][i+n-1]);
		ansmax=max(ansmax,d[i][i+n-1]);
	}
											//	printf("%d\n%d",f[1][2*n],d[1][2*n]);
	printf("%d\n%d",ansmin,ansmax);
	return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,b[207],f[207][207],ans;
int main()
{
	int i,j,k,iiiii;
	scanf("%d",&T);
	for(iiiii=1;iiiii<=T;iiiii++)
	{
		memset(f,127/3,sizeof(f));
			
		
		scanf("%d",&n);
						//	printf("%d",f[n][n]);
		for(i=1;i<=n;i++)
			scanf("%d",&f[i][i]);
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
			
		for(j=1;j<=n-1;j++)
			for(i=1;i+j<=n;i++)
				for(k=i;k<=i+j;k++)
					f[i][i+j]=min(f[i][i+j],min(f[i][k]+f[k+1][i+j]+b[k+1],f[i][k]+f[k+1][i+j]+b[k]));
			
	//	printf("\n");
	//	for(i=1;i<=n;i++)
	//	{
	//		for(j=1;j<i;j++)
	//			printf("\t");
	//		for(j=i;j<=n;j++)
	//			printf("\t%d",f[i][j]);
	//		printf("\n");
	//	}
			
		ans=1000000001;
		for(i=1;i<=n;i++)
		{
			ans=min(ans,min(f[1][i]+f[i+1][n]+b[i],f[1][i]+f[i+1][n]+b[i+1]));
		}	
		printf("Case #%d: %d",iiiii,f[1][n]);
	} 
	return 0;
}

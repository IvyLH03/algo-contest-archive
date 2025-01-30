#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[201],b[201],f[201][201];
int main()
{
	int i,j,k,iiiii,len;
	scanf("%d",&t);
	for(iiiii=1;iiiii<=t;iiiii++)
	{
		memset(f,127/3,sizeof(f));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&f[i][i]);
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(len=1;len<n;len++)
			for(i=1;i+len<=n;i++)
			{
				j=i+len;
				for(k=i;k<=j;k++)
				{
					if(k==i)
						f[i][j]=min(f[i][j],f[i][i]+f[i+1][j]+b[i]);
					else 
					{
						if(k==j)
							f[i][j]=min(f[i][j],f[i][j-1]+f[j][j]+b[j]);
						else
							f[i][j]=min(f[i][j],f[i][k-1]+f[k][k]+f[k+1][j]+b[k]+b[k]);	
					}
				}
			}
			printf("%d\n",f[1][n]);
	}
	return 0;
} 






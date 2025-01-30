#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[3007],n,f[3007][3007],ans;
int main()
{
	int i,j,len;
	scanf("%d",&n);
	while(n)
	{
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i+n]=a[i];
			f[i][i]=f[i+n][i+n]=1;
			//f[i][i]=1;
		}
		
		for(len=1;len<2*n;len++)
	//	for(len=1;len<n;len++)
		{
			for(i=1;i<=2*n;i++)
		//	for(i=1;i<=n;i++)
			{
				j=i+len;
				if(j>2*n) continue;
			//	if(j>n) continue;
				f[i][j]=max(f[i][j],max(f[i+1][j],f[i][j-1]));
				if(a[i]==a[j]) f[i][j]=max(f[i][j],f[i+1][j-1]+2);
			}
		}
		
		ans=0;
		for(i=1;i<=2*n;i++)
		//for(i=1;i<=n;i++)
		{
			for(j=i;j<=i+n-1;j++)
				ans=max(ans,f[i][j]+f[j+1][i+n-1]);
		//	ans=max(ans,f[1][i]+f[i+1][n]);
			
		}
		printf("%d\n",ans);
		scanf("%d",&n);
	}
	return 0;
}

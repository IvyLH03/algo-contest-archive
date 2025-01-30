#include<cstdio>
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;
} 
int min(int a,int b)
{
	return a>b?b:a;
}
int f1[202][202],f2[202][202],a[202][202],n;
int main()
{
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i][i]);
		a[i+n][i+n]=a[i][i];
	}
	n*=2;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
			a[j][i+j]=a[j][j]+a[j+1][i+j];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			for(k=1;k<=i;k++)
				{
					f1[j][i+j]=max(f1[j][i+j],a[j][i+j]+f1[j][j+k-1]+f1[j+k][i+j]);
					if(k==1)
						f2[j][i+j]=a[j][i+j]+f2[j][j+k-1]+f2[j+k][i+j];
					else
						f2[j][i+j]=min(f2[j][i+j],a[j][i+j]+f2[j][j+k-1]+f2[j+k][i+j]);
				}
				
		}
	}	
	n/=2;
	int ans1=0,ans2=f2[1][n];
	for(i=1;i<=n+1;i++)
	{
		ans1=max(ans1,f1[i][n+i-1]);
		ans2=min(ans2,f2[i][n+i-1]);
	}
	printf("%d\n%d",ans2,ans1);
	return 0;
}

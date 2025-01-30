#include<cstdio>
#include<cstring>
using namespace std;
int a[100][100],n,x,f[100],c[100];
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<n;i++)
		f[i]=1000000;
	for(i=n-1;i>=1;i--)
		for(x=i+1;x<=n;x++)
		{
			if((a[i][x])&&(f[x]!=100000)&&(f[i]>a[i][x]+f[x]))
			{
				f[i]=a[i][x]+f[x];
				c[i]=x;
			} 
		}
	printf("minlong=%d\n",f[1]);
	x=1;
	while(x!=0)
	{
		printf("%d ",x);
		x=c[x];
	}
	return 0;
} 

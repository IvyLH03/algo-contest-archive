#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100][100],minn[100],nx[100];
int main()
{
	memset(minn,1,sizeof(minn));
	int n,i,j,r=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	minn[n]=minn[n-1]=0;
	for(i=n-2;i>=1;i--)
	{
		for(j=i;j<=n;j++)
		{
			if(a[j][i]!=0&&a[j][i]<minn[i])
			{
				minn[i]=minn[j]+a[j][i];
				nx[i]=j;
			}
				
		}
	}
	printf("minlong=%d\n1 ",minn[1]);
	while(r!=n)
	{
		r=nx[r];
		printf("%d",r);
	}
}

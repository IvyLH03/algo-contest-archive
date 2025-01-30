#include<cstdio>
#include<algorithm> 
using namespace std;
int f[101][3],a[101],n,minn;
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i][1]=1;
		f[i][2]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<i;j++)
			if(a[j]<a[i])
				f[i][1]=max(f[i][1],f[j][1]+1);
	}
	for(i=n;i>=1;i--)
	{
		for(j=n;j>i;j--)
			if(a[j]<a[i])
				f[i][2]=max(f[i][2],f[j][2]+1);
	}
	minn=0x7ffffff;
	for(i=1;i<=n;i++)
	{
		minn=min(minn,n-f[i][1]-f[i][2]+1);
	}
	printf("%d",minn);
	return 0;
}

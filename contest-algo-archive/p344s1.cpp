#include<cstdio>			//f=max(f[i],f[j]+1);
#include<algorithm> 
using namespace std;
int n,a[1001],f[1001],ans;
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=1;
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=i+1;j<=n;j++)
			if(a[j]>a[i])
				f[i]=max(f[i],f[j]+1);
		ans=max(f[i],ans);
	}
	printf("%d",ans);
	return 0;
}

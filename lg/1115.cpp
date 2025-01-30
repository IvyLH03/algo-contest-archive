#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[200007],d[200007],ans;
int main()
{
	int i,j,k;
	ans=-200007;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		d[i]=d[i-1]+k;
	}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
		{
			if(i!=j&&d[j]-d[i-1]<0) break;
			ans=max(ans,d[j]-d[i-1]);
		}
	printf("%d",ans);
	return 0;
}

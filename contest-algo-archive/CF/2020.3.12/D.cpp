#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200007;
int a[N],b[N],s[N];
int main()
{
	int t,n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			s[i]=a[i]-b[i];
		}
	sort(s+1,s+1+n);
	long long ans=0;
	for(int i=1;i<n;i++)
	{
		int p=i;
		for(int j=i+1;j<=n+1;j++)
			if(s[i]>s[j]*(-1))
			{
				p=j;break;
			}
		ans+=n-p+1;
	}
		printf("%lld\n",ans);
	return 0;
}

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
	long long ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
			if(s[i]>s[j]*(-1)) ans++;
	}
		printf("%lld\n",ans);
	return 0;
}

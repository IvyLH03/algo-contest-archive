#include<cstdio>
using namespace std;
const int N=100007;
long long n,x,a[N],ans;
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if(a[i]>x) ans+=a[i]-x,a[i]=x;
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]+a[i-1]<=x) continue;
		long long u=a[i]+a[i-1]-x;ans+=u,a[i]-=u;
	}
	printf("%lld",ans);
	return 0;
}

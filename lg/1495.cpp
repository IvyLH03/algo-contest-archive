#include<cstdio>
using namespace std;
long long n,ans,a[20],b[20],m;
void exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;y=0;return;
	}
	exgcd(b,a%b,x,y);
	int temp=x;x=y;
	y=temp-(a/b)*y;
}
int main()
{
	scanf("%lld",&n);m=1;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		m*=a[i];
	}
	long long x,y;
	for(long long i=1;i<=n;i++)
	{
		long long s=m/a[i];
		exgcd(s,a[i],x,y);
		ans=((ans+s*x*b[i]%m)+m)%m;
	}
	printf("%lld",ans%m);
	return 0;
}

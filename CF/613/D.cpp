#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
int a[32];
int main()
{
	ll n,andn,orn,x,maxx=0,ans=0;
	scanf("%lld%lld",&n,&x);andn=orn=x;
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&x);
		andn&=x;orn|=x;
		maxx=maxx>x?maxx:x;
	}
	printf("andn=%d,orn=%d\n",andn,orn);
	for(ll i=0;i<=30;i++)
	{
		int andnn=andn&(1<<i),ornn=orn&(1<<i);
		if(andnn==0&&ornn>0) ans+=1<<i;
	}
	printf("%lld",ans);
	return 0;
}

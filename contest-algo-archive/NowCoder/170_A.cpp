#include<cstdio>
#include<cmath>
using namespace std;
long long l,r,ans,n,i,t,x;
int main()
{
	scanf("%lld%lld",&l,&r);
	n=1;x=1;
	for(i=1;i<=r;i++)
	{
		t++;
		if(t>x)
		{
			n++;
			x=n*n;
			t=1;
		}
		if(i>=l)
		{	
			ans+=n;
					//printf("%lld\n",n);
		}
					//	printf("%lld %lld\n",n,x);
	}
	printf("%lld",ans);
	return 0;
	
}

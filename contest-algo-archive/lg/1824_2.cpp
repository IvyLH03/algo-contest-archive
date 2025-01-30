#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
long long a[1000001];
bool pd(long long x)
{
	int i,tot=1;
	long long r=a[1];
	for(i=2;i<=m;i++)
	{
		while(a[tot]-r<=x)
		{
			tot++;
			if(tot>n)
				return 0;
		}
		r=a[tot];
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	long long z=1000000001,y=0,mid;
	for(i=2;i<=n;i++)
	{
		long long r=a[i]-a[i-1];
		z=min(z,r);
	}
	y=a[n]-a[1];
	while(z<y)
	{
		mid=(z+y)/2;
		if(pd(mid))
			z=mid+1;
		else
			y=mid;
	}
	
	printf("%lld",z);
	return 0;
}

#include<cstdio>
using namespace std;
long long n,a[500001],k[500001],ans;
void sort(long long z,long long y)
{	
	if(z==y)
		return;
	long long mid=(z+y)/2;
	sort(z,mid);
	sort(mid+1,y);
	long long t=z,i=mid+1,r=z-1;
	while(t<=mid&&i<=y)
	{
		if(a[t]>a[i])
		{
			k[++r]=a[i++];
			ans+=(mid-t+1);
		}	
		else
			k[++r]=a[t++];
	}
	while(t<=mid)
		k[++r]=a[t++];
	while(i<=y)
		k[++r]=a[i++];
	for(i=z;i<=y;i++)
		a[i]=k[i];
}
int main()
{
	scanf("%lld",&n);
	long long i;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(1,n);
	printf("%lld",ans);
	return 0;
}

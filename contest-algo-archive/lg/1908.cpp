#include<cstdio>
using namespace std; 
long long n;
int a[500001],k[500001];
long long ans;
void search(long long l,long long r)
{
	if(l==r)
		return;
	long long mid=(l+r)/2;
	search(l,mid);
	search(mid+1,r);
	long long i=l,j=mid+1,t=l;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j])
		{
			k[t++]=a[i++];
		}
		else
		{
			k[t++]=a[j++];
			ans+=mid-i+1;
		}
	}
	while(i<=mid)
	{
		k[t++]=a[i++];
	}
	while(j<=r)
	{
		k[t++]=a[j++];
	}
	for(i=l;i<=r;i++)
		a[i]=k[i];
}
int main()
{
	scanf("%d",&n);
	long long i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	search(1,n);
	printf("%lld",ans);
	return 0;
}


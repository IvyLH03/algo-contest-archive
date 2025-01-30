#include<cstdio>
using namespace std;
const int N=31;
long long a[N];
int k,n,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		long long maxa=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) 
		{
			scanf("%lld",&a[i]);
			maxa=a[i]>maxa?a[i]:maxa; 
		}
		long long ktmp=k;bool flag=0;
		while(ktmp*k<=maxa) ktmp*=k;
		while(ktmp)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]>=ktmp)
				{
					a[i]-=ktmp;break;
				}
			}
			ktmp/=k;
		}
		for(int i=1;i<=n;i++) if(a[i]) flag=1;
		if(flag) printf("NO\n");
		else printf("YES\n");
		
	}
	return 0;
}

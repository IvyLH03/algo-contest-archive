#include<cstdio>
using namespace std;
int n,a[500001],r[500001];
long long tot;
void msort(int s,int t)
{
	if(s==t)return;
	int mid=(s+t)/2;
	msort(s,mid);
	msort(mid+1,t);
	int i=s,j=mid+1,k=s;
	while(i<=mid&&j<=t)
	{
		if(a[i]<=a[j])
		{
			r[k]=a[i];k++;i++;
		}
		else
		{
			r[k]=a[j];k++;j++;
			tot+=mid-i+1;
		}
	}
	while(i<=mid)
	{
		r[k]=a[i];k++;i++;
	}
	while(j<=t)
	{
		r[k]=a[j];k++;j++;
	}
	for(int i=1;i<=t;i++)
		a[i]=r[i];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	msort(1,n);
	printf("%lld",tot);
	return 0;
}

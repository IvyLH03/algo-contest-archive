#include<cstdio>
using namespace std;
int d,n,m,a[50002],ans;
bool pd(int mid)
{
	int tot=0,i=0,t=0;
	while(i<n+1)
	{
		i++;
		if(a[i]-a[t]<mid)
			tot++;
		else
			t=i;
	}
	if(tot>m)
		return 0;
	return 1;
}
int main()
{
	scanf("%d%d%d",&d,&n,&m);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1]=d;
	int l=1,r=d,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(pd(mid))
		{
			ans=mid;
			l=mid+1;
		}	
		else r=mid-1;
	} 
	printf("%d",r);
	return 0;
}

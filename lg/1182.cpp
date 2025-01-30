#include<cstdio>
using namespace std;
int n,m,a[1000001],maxn,tot;
bool pd(int x)
{
	int tot=0,num=1,i;
	for(i=1;i<=n;i++)
	{
		if(tot+a[i]<=x)
			tot+=a[i];
		else
		{
			num++;tot=a[i];
		}
		if(num>m)
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=a[i]>maxn?a[i]:maxn;
		tot+=a[i];
	} 
	int z=maxn,y=tot,mid;
	while(z<y)
	{
		mid=(z+y)/2;
		if(pd(mid))
			y=mid;
		else
			z=mid+1;
	}
	printf("%d",z);
	return 0;
	
}

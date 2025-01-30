#include<cstdio>
using namespace std;
int l,m,n,a[10001];
int main()
{
	scanf("%d%d%d",&l,&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1]=l; 
	int z=1,y=l,mid;
	while(z<=y)
	{
		int tot=0;
		mid=(z+y/2);
		i=1;j=0;
		while(i<=n)
		{
			if(a[i]-a[j]<mid)
			{
				tot++;i++;
			}
			else
			{
				j++;i++;
			}
			if(tot>m)
				break;
		}
		if(tot>m)
			y=mid-1;
		else
			z=mid+1;
	}
	printf("%d",z);
	return 0;
} 

//luogu P1182 ÊýÁÐ·Ö¶Î¡®Section II¡¯ 
#include<cstdio>
using namespace std;
int n,m,a[100001];
bool pd(int x)
{
	int t=0,s=0,y=1;
	while(t<n)
	{
		t++;
		if(s+a[t]<=x) s+=a[t];
		else 
		{
			y++;s=a[t];
		}
	}
	if(y>m) return 0;
	return 1;
}
int main()
{
	int i,z=0,y=0,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		y+=a[i];if(a[i]>z) z=a[i];
	}
	
	while(z<=y)
	{
		mid=z+(y-z)/2;
		if(pd(mid)) y=mid-1;
		else z=mid+1;
	}
	
	printf("%d",mid);
	return 0;
}
 

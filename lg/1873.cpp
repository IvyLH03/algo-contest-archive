//luogu P1873¿³Ê÷ 
#include<cstdio>
using namespace std;
int n,m,a[1000001];
bool pd(int x)
{
	int tot=0,i;
	for(i=1;i<=n;i++)
	{
		if(a[i]-x>0)
			tot+=a[i]-x;
		if(tot>=m)	return 1;
	}
	return 0;
}
int main()
{
	int i,maxn=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxn) maxn=a[i];
	}
		
	int z=1,y=maxn,mid;
	while(z<=y)
	{
		mid=(z+y)/2;
		if(!pd(mid)) y=mid-1;
		else z=mid+1;
	}
	printf("%d",y);
	return 0;
} 

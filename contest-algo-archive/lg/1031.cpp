#include<cstdio>
using namespace std;
int n,fn,ave,y;
int a[101];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		fn+=a[i];
	}
	ave=fn/n;
	for(int i=1;i<=n;i++)
		a[i]-=ave;
		
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
		{
			a[i+1]+=a[i];
			y++;a[i]=0;
		}
	}
	printf("%d",y);
	return 0;
}

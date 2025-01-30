#include<cstdio>
#include<algorithm>
using namespace std;
int a[30001],tot;
int main()
{
	int g,n;
	scanf("%d%d",&g,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int t=1;
	for(int i=n;i>=t;i--)
	{
		if(a[i]+a[t]<=g)
			t++;
		tot++;
	}
	printf("%d",tot);
	return 0;
}

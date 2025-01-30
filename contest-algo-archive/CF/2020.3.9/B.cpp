#include<cstdio>
#include<algorithm>
using namespace std;
const int N=101;
int a[N];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--) printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}

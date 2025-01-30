#include<cstdio>
#include<algorithm>
using namespace std;
int a[100001];
int main()
{
	int n,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	sort(a+1,a+1+n);
	for(int i=n;i>=n-k;i--)
		printf("%d\n",a[i]);
	return 0;
} 

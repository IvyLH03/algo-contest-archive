#include<cstdio>
using namespace std;
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n+1];
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n-1;i++)
		printf("%d ",a[n-i+1]);
	printf("%d",a[1]);
	return 0;
}

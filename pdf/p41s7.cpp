#include<cstdio>
int a[1001],b[1001];
using namespace std;
int main()
{
	int n,i,y=0;
	scanf("%d",&n);

	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(i=1;i<=n;i++) y+=a[i]*b[i];
	printf("%d",y);
	return 0;
} 

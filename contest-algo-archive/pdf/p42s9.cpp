#include<cstdio>
using namespace std;
int a[10001];
int main()
{
	int n,i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&x);
	for(i=1;i<=n;i++)
		if(a[i]==x)
		{
			printf("%d",i);
			break;
		}
	return 0;
}

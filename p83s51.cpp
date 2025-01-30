#include<cstdio>
using namespace std;
int a[100];
int main()
{
	int x,n=0,i;
	while(~scanf("%d",&x))
		a[n++]=x;
	for(i=n-1;i>=1;i--)
		printf("%d ",a[i]);
	printf("%d\n",a[0]);
	return 0;
}

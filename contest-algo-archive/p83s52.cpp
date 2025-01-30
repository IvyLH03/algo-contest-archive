#include<cstdio>
const int n=10;
using namespace std;
int a[n];
int main()
{
	int i;
	printf("read %d datas:\n",n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i-1]);
	int temp=a[0];
	for(i=0;i<=n-1;i++)
		a[i]=a[i+1];
	a[n-1]=temp;
	printf("Result:\n");
	for(i=0;i<=n-1;i++)
		printf("%3d",a[i]);
	
	
	
	return 0;
}

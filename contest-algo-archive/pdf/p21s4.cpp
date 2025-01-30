#include<cstdio>
using namespace std;
int main()
{
	int a,b,n,i;
	scanf("%d%d",&n,&a);
	for(i=2;i<=n;i+=1)
	{
		scanf("%d",&b);
		if(b>a) a=b;
	}
	printf("%d",a);
	return 0;
}

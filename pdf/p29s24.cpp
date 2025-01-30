#include<cstdio>
using namespace std;
int main()
{
	int a,b,n,i,xs,y;
	
	scanf("%d%d%d",&a,&b,&n);
	for(i=1;i<=n;i+=1)
	{
		a%=b;a*=10;
	}
	y=a/b;
	printf("%d",y);
	
	return 0;
}

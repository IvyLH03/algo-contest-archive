#include<cstdio>
using namespace std;
int main()
{
	int x,y=0,n=0,i=1,nzh=n;
	scanf("%d",&x);
	int xzh=x;
	while(xzh!=0)
	{
		nzh=xzh%10;
		xzh=(xzh-nzh)/10; 
		i*=10;
	}
	while(x!=0)
	{
		i/=10; 
		n=x%10;
		y+=n*i;
		x=(x-n)/10; 
		
	}
	printf("%d",y);
	return 0;
}

#include<cstdio>
using namespace std;
int main()
{
	int i,n,x,a,b;
	for(i=1;;i++)
	{
		x=i*i;
		if(x<1000)
			continue;
		if(x>9999)
			break;
		a=x/100;
		b=x%100;
		if(a/10==a%10&&b/10==b%10)
			printf("%d\n",x);
		
	}
	return 0;
}

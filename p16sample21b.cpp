#include<cstdio>
using namespace std;

int main()
{
	double a,b,c;
	printf("Input a,b");
	scanf("%lf%lf",&a,&b);
	c=a;
	a=b;
	b=c;
	printf("a=%lf b=%lf",a,b);
	
	return 0;
}

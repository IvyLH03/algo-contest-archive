#include<cstdio>
using namespace std;

int main()
{
	float a,b,c;
	printf("Input a,b");
	scanf("%f%f",&a,&b);
	c=a;
	a=b;
	b=c;
	printf("a=%f b=%f",a,b);
	
	return 0;
}

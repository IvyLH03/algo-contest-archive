#include<cstdio>
using namespace std;

int main()
{
	
	const double pi=3.1415926; //可以写在main函数外
	float r,c,s;
	scanf("%f",&r);
	c=2*pi*r;
	s=pi*r*r;
	printf("c=%f s=%f",c,s);
	return 0;
	 
}

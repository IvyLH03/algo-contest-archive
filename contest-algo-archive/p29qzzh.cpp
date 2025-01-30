#include<cstdio>
using namespace std;

int main()
{
	int b=7;
	float a=2.5,c=4.7;
	printf("%f",a+(int)(b/3*(int)(a+c)/2.0)%4);
	return 0;
	
}

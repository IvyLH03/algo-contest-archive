#include<cstdio>
using namespace std;
int main()
{
	float a,b;
	scanf("%f",&a);
	if(a>=0)
		b=a;
	else
		b=(-1)*a;
	printf("%.2f",b);
	return 0;

}

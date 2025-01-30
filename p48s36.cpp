#include<cstdio>
using namespace std;
int main()
{
	float a,b;
	scanf("%f",&a);
	if(a<=20)
	{
		b=a*1.68;
	}
	else
	{
		b=a*1.98;
	}
	printf("%.2f",b);
	return 0;
}

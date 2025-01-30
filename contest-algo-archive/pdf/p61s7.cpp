#include<cstdio>
#include<cmath>
using namespace std;
double arctanx(double x);
int main()
{
	double pi=6*arctanx(1.0/sqrt(3));
	printf("%lf",pi);
	return 0;
}
double arctanx(double x)
{
	int k=0;
	double s=x,sum=0;
	while(abs(s/(2*k+1))>=0.000006)
	{
		sum+=(s/(2*k+1));
		k++;s*=x*x*(-1);
		//printf(".\n");
	}
	return sum;
}

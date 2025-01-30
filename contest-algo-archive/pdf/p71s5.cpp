#include<cstdio>
using namespace std;
double f(double x,double n)
{
	if(n==1)return x/(1+x);
	else return x/(n+f(n-1,x));
}
int main()
{
	double x,n;
	scanf("%lf%lf",&x,&n);
	printf("%lf",f(x,n));
	return 0;
}

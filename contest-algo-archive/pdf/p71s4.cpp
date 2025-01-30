#include<cstdio>
#include<cmath>
using namespace std;
double f(double x,double n)
{
	if(n==1)return sqrt(n+x);
	else return sqrt((n)+f(x,n-1));
}
int main()
{
	double x,n;
	scanf("%lf%lf",&x,&n);
	printf("%lf\n",f(x,n));
	return 0;
}

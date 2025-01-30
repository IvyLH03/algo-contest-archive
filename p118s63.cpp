#include<cstdio>
#include<cmath>
using namespace std;
double area(double,double,double);
int main()
{
	double b1,b2,b3,b4,b5,b6,b7,s;
	printf("please input b1,b2,b3,b4,b5,b6,b7:\n");
	scanf("%f%f%f%f%f%f%f",b1,b2,b3,b4,b5,b6,b7);
	s=area(b1,b5,b6)+area(b6,b2,b7)+area(b7,b3,b4);
	printf("s=%10.3lf\n",s);
	return 0;	
}
double area(double a,double b,double c)
{
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

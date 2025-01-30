#include<cstdio>
using namespace std;
//求圆柱体体积 
int main()
{
	const double pi=3.1415926;
	double r,h,s1,s2,s;
	scanf("%lf%lf",&r,&h);
	s1=pi*r*r;
	s=s1*h;
	printf("v=%.3lf",s);
	return 0;
}

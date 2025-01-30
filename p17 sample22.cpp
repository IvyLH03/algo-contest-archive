#include<cstdio>
using namespace std;
//求圆柱体表面积 
int main()
{
	const double pi=3.1415926;
	double r,h,s1,s2,s;
	scanf("%lf%lf",&r,&h);
	s1=pi*r*r;
	s2=pi*2*r*h;
	s=2*s1+s2;
	printf("s=%.3lf",s);
	return 0;
}

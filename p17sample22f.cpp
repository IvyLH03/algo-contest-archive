#include<cstdio>
using namespace std;
//给出半径求球表面积体积
//球表面积S=4*pi*r^2
//球体积=4/3*pi*r^3 
int main()
{
	const double pi=3.1415926;
	double r,v,s;
	scanf("%lf",&r);
	s=4*pi*r*r;
	v=4.0/3*pi*r*r*r; //若使用4/3，则作整形变量计算 
	printf("s=%.3lf v=%.3lf",s,v);
	return 0;
}

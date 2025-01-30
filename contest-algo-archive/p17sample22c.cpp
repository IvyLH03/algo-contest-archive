#include<cstdio>
using namespace std;
//给出半径求圆面积 
int main()
{
	const double pi=3.1415926;
	double r,s;
	scanf("%lf",&r);
	s=pi*r*r;
	
	printf("s=%.3lf",s);
	return 0;
}

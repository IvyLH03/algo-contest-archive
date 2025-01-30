#include<cstdio>
using namespace std;
//给出半径求圆周长 
int main()
{
	const double pi=3.1415926;
	double r,s;
	scanf("%lf",&r);
	s=pi*2*r;
	printf("s=%.3lf",s);
	return 0;
}

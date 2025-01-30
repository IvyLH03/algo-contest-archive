#include<cstdio>
using namespace std;
double akm(double m,double n)
{
	if(m==0)return n+1;
	if(m>0&&n==0)return akm(m-1,1);
	if(m>0&&n>0)return akm(m-1,akm(m,n-1));	
}
int main()
{
	double m,n;
	scanf("%lf%lf",&m,&n);
	printf("%lf",akm(m,n) );
	return 0;
}

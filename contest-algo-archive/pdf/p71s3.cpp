#include<cstdio>
using namespace std;
double hn(double x,int n)
{
	if(n==0)return 1;
	if(n==1)return 2*x;
	if(n>1)return 2*x*hn(x,n-1)-2*(n-1)*hn(x,n-2);
}
int main()
{
	int n;
	double x;
	scanf("%lf%d",&x,&n);
	printf("%lf\n",hn(x,n));
	return 0;
} 

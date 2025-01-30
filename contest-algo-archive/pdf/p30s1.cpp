#include<cstdio>
using namespace std;
int main()
{
	int h,i=10;
	scanf("%d",&h);
	double x=h,y=x;
	while(i!=0)
	{
		i--;
		x/=2;
		y+=2*x;
	}
	printf("%g\n%g",y,x);
	
	return 0;
}

#include<cstdio>
using namespace std;
int main()
{
	int n,a;
	float s=0;
	scanf("%d",&n);
	if(n<=5000)
	{
		printf("%d",n);
		return 0;
	}
	a=n-5000;
	if(a>80000)
	{
		s+=(a-80000)*0.45;
		a=80000;
	}
	if(a>55000)
	{
		s+=(a-55000)*0.35;
		a=55000;
	}
	if(a>35000)
	{
		s+=(a-35000)*0.3;
		a=35000;
	}
	if(a>25000)
	{
		s+=(a-25000)*0.25;
		a=25000;
	}
	if(a>12000)
	{
		s+=(a-12000)*0.2;
		a=12000;
	}						
	if(a>3000)
	{
		s+=(a-3000)*0.1;
		a=3000;
	}						
	s+=a*0.03;				
	n-=s;
	printf("%d",n);
	return 0;
}

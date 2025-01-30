#include<cstdio>
using namespace std;
char pd(int x)
{
	int nm1=0,nm0=0;
	while(x!=0)
	{
		if(x%2==1)nm1++;
		if(x%2==0)nm0++;
		x/=2;
	}
	if(nm1>nm0) return 'A';
	if(nm0>nm1) return 'B'; 
}
int main()
{
	int a=0,b=0;
	for(int i=1;i<=1000;i++)
	{
		if(pd(i)=='A')a++;
		if(pd(i)=='B')b++;
	}
	printf("%d %d",a,b);
	return 0;
}

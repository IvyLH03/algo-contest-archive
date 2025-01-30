#include<cstdio>
using namespace std;
int main()//qi/pi
{
	int n,i,p1=1,q1=2,qi=q1,pi=p1,empt;
	float r=0;
	scanf("%d",&n);
	r=1.0*q1/p1;
	for(i=1;i<=(n-1);i+=1)
	{
		empt=qi;
		qi=qi+pi;
		pi=empt;
		r=r+1.0*qi/pi;
	}
	printf("%.4f",r);
	
	return 0;
}

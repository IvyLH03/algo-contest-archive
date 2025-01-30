#include<cstdio>
using namespace std;
void pd(int x);
int main()
{
	for(int i=2;i<=100;i++)
	{
		pd(i);
	}
	return 0;
}
void pd(int x)
{
	int i,s=0;
	for(i=1;i<x;i++)
		if(x%i==0)s+=i;
	if(s==x)printf("%d\n",x);
}


#include<cstdio>
#include<cmath>
using namespace std;
void ss(int x);
bool pd[101];
bool pds(bool pd[])
{
	for(int i=2;i<=100;i++)
	{
		for(int j=3;j<=100;j++)
			if(j%i==0&&j!=i)pd[j]=1;
	}
	for(int j=2;j<=100;j++)
	{
		if(pd[j]==1)pd[j]=0;
		else pd[j]=1;
	}
}
int main()
{
	pds(pd);
	for(int i=6;i<=100;i+=2)
		ss(i);
	return 0;
}
void ss(int x)
{
	int a,b;
	for(int i=2;i<x;i++)
	{
		if(pd[i]==1&&pd[x-i]==1)
		{
			a=i;b=x-i;
			break;
		}
	}
	printf("%d=%d+%d\n",x,a,b);
}

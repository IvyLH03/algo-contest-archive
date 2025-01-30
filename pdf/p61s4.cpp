#include<cstdio>
using namespace std;
bool a[100];
void pd(bool[]);
int main()
{
	pd(a);
	for(int i=11;i<=99;i++)
		if(!a[i])printf("%5d",i);
	return 0;
	
}
void pd(bool a[])
{
	for(int i=2;i<=99;i++)
	{
		for(int j=11;j<=99;j++)
			if(j%i==0&&j!=i)a[j]=1;
	}
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
			if(a[10*i+j]!=a[10*j+i])a[10*i+j]=a[10*j+i]=1;
	}
}

#include<cstdio>
using namespace std;
int fac(int x);
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	printf("%d",fac(m)/(fac(m-n))*(fac(n)));
	return 0;
}
int fac(int x)
{
	int s=1,i;
	for(i=1;i<=x;i++)
	 s*=i;
	return s;
}

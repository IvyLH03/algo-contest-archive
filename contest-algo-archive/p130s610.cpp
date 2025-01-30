#include<cstdio>
using namespace std;
int x;
int xn(int n)
{
	if(n==0)return 1;
	else return x*xn(n-1); 
}
int main()
{
	int n;
	scanf("%d%d",&x,&n);
	printf("%d^%d=%d",x,n,xn(n));
	return 0;
}

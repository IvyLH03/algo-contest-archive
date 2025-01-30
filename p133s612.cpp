#include<cstdio>
using namespace std;
int ys(int m,int n)
{
	return n==0? m:ys(n,m%n);
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	printf("%d",ys(m,n));
	return 0;
}

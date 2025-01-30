#include<cstdio>
using namespace std;
int jc(int x)
{
	if(x==0)return 1;
	else return x*jc(x-1);
}
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",jc(x));
	return 0;
}


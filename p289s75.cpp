#include<cstdio>
using namespace std;
int b,p,k,a;
int f(int p)
{
	if(p==0)
		return 1%k;
	int tmp=f(p/2)%k;
	tmp=(tmp*tmp)%k;
	if(p%2==1)
		tmp=(tmp*b)%k;
	return tmp;
}
int main()
{
	scanf("%d%d%d",&b,&p,&k);
	int tmpb=b;
	b%=k;
	printf("%d^%d mod %d=%d",tmpb,p,k,f(p));
	return 0;
}

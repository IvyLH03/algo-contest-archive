#include<cstdio>
using namespace std;
int main()
{
	int m,n,a=0,b,i;
	scanf("%d%d",&m,&n);
	for(i=1;i<=(n-m+1);i+=1)
	{
		b=m+i-1;
		if(b%2==1)
		a+=b;
	}
	printf("%d",a);
	return 0;
}

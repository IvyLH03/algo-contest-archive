#include<cstdio>
using namespace std;

int main()
{
	int a,b,c;
	printf("Input a,b");
	scanf("%d%d",&a,&b);
	c=a;
	a=b;
	b=c;
	printf("a=%d b=%d",a,b);
	
	return 0;
}

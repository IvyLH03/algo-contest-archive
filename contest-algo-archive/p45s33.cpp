#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,temp;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b)
	{
		temp=a;a=b;b=temp;
	}
	if(b<c)
	{
		temp=b;b=c;c=temp;
	}
	if(a<c)
	{
		temp=c;c=a;a=temp;
	}
	printf("%d%d%d",a,b,c);
	return 0;
}

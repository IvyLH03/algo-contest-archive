#include<cstdio>
using namespace std;
int main()
{
	float a,b,c,empt;
	scanf("%f%f%f",&a,&b,&c);
	if(a<b)
	{
		empt=a;a=b;b=empt;
	}
	if(b<c)
	{
		empt=b;b=c;c=empt;
	}
	if(a<c)
	{
		empt=a;a=c;c=empt;
	}
	if(b+c>a&&a-b<c)
		printf("yes");
	else
		printf("no");
	return 0;
}

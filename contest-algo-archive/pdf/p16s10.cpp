#include<cstdio>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<60)
	{
		if(b<60)
			printf("0");
		else
			printf("1");
	}
	else
	{
		if(b<60)
			printf("1");
		else
			printf("0");
	}
	return 0;	
}

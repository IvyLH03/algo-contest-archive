#include<cstdio>
using namespace std;
int main()
{
	int i,k;
	for(i=1;i<=5;i++)
	{
		for(k=1;k<=5-i;k++)
			printf(" ");
		for(k=1;k<=2*i-1;k++)
			printf("*");
		for(k=1;k<=5-i;k++)
			printf(" ");
		printf("\n");
	}
	return 0;
}

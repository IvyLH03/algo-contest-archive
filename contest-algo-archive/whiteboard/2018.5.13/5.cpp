#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int i,k;
	for(i=-2;i<=3;i++)
	{
		for(k=1;k<=abs(i);k++)
			printf(" ");
		for(k=1;k<=(2*(3-abs(i))-1);k++)
			printf("*");
		printf("\n");
		
		
	}
	return 0;
}

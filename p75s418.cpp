#include<cstdio>
using namespace std;
int main()
{
	int n,i=2;
	scanf("%d",&n);
	printf("%d=",n);
	do
	{
		while(n%i==0)
		{
			printf("%d",i);
			n/=i;
			if(n!=1)
				printf("*");
		}
		i++;
	}
	while(n!=1);
	return 0;
}

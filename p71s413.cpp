#include<cstdio>
using namespace std;
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i+=1)
	{
		for(j=1;j<=i;j+=1)
			printf("* ");
		printf("\n");
	}
	return 0;
}

#include<cstdio>
using namespace std;
int main()
{
	int x,n;
	scanf("%d",&x);
	while(x!=1)
	{
		if(x%2==0)
		{
			n=x/2;
			printf("%d/2=%d\n",x,n);
			x=n;
		}
		else
		{
			n=x*3+1;
			printf("%d*3+1=%d\n",x,n);
			x=n;
			
		}
	}
	printf("END");
	return 0;
}

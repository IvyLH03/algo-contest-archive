#include<cstdio>
using namespace std;
int main()
{
	int n,x;
	scanf("%d",&n);
	while(n!=0)
	{
		x=n%10;
		n=(n-x)/10;
		printf("%d ",x);
	}
	
	return 0;
}

#include<cstdio>
using namespace std;
int i;
int fsl(int n)
{
	if(n==1||n==2)return n-1;
	else return fsl(n-2)+fsl(n-1);
}
int main()
{
	i=1;
	int n;
	scanf("%d",&n);
	printf("%d\n",fsl(n));
	return 0;
}

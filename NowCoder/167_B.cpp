#include<cstdio>
using namespace std;
int n,i;
int main()
{
	scanf("%d",&n);
	double s=1;
	for(i=1;i<=n;i++)
		s*=0.5;
	printf("%0.*lf",n,s);
	return 0;
} 

#include<cstdio>
using namespace std;
int main()
{
	int m;
	scanf("%d",&m);
	int a=m/100;
	int b=(m/10)%10;
	int c=m%10;
	int n=100*c+10*b+a;
	printf("%d",n);
	return 0; 
}

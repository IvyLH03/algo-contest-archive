#include<cstdio>
using namespace std;
bool check(int,int);
int main()
{
	int a,b;
	printf("input n,d\n");
	scanf("%d%d",&a,&b);
	if(check(a,b)==1)printf("true");
	else printf("fales");
	return 0;
}
bool check(int n,int d)
{
	int s;bool t=0;
	while(n)
	{
		s=n%10;
		n/=10;
		if(d==s)t=1;
	}
	return t;
}

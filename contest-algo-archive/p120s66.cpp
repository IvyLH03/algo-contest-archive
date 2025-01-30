#include<cstdio>
using namespace std;
int x,y;
int gcd(int x,int y)
{
	int r=x%y;
	while(r!=0)
	{
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}

int lcm()
{
	return x*y/gcd(x,y);
}

int main()
{
	scanf("%d%d",&x,&y);
	printf("%d",lcm());
	return 0;
}

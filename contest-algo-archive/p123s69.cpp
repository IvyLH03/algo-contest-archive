#include<cstdio>
using namespace std;
void common(int x,int y);
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	common(x,y);
}
void common(int x,int y)
{
	int m=x,n=y,r;
	do
	{
		r=m%n;
		m=n;
		n=r;
	}
	while(r!=0);
	x/=m;y/=m;
	printf("%5d%5d",x,y);
}

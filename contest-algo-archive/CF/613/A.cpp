#include<cstdio>
using namespace std;
int cnt1,cnt2,n;
int rd()
{
	int x=0;char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';c=getchar();
	}
	return x;
}
int main()
{
	n=rd();char c;
	while(n--)
	{
		c=getchar();
		if(c=='L') cnt1++;else cnt2++;
	}
	printf("%d",cnt1+cnt2+1);
}

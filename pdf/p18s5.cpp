#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,maxn;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b&&a>c)
		maxn=a;
	else if(b>a&&b>c)
			maxn=b;
		 else
		 	maxn=c;
	printf("%d",maxn);
	return 0;
}

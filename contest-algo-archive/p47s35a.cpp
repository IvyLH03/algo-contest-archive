#include<cstdio>
using namespace std;
int main()
{
	float a,b,c,maxn;
	scanf("%f%f%f",&a,&b,&c); 
	if(a>b&&a>c)
		maxn=a;
	else if(b>a&&b>c)
			maxn=b;
		 else
		 	maxn=c;
	printf("%f",maxn);
	return 0;
}

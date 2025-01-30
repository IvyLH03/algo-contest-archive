#include<cstdio>
using namespace std;
int main()
{
	float a,b,c,maxn;
	scanf("%f%f%f",&a,&b,&c);
	maxn=a;
	if(b>maxn)
		maxn=b;
	if(c>maxn)
		maxn=c;
	printf("%f",maxn);
	return 0;
}

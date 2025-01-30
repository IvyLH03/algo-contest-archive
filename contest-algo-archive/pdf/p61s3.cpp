#include<cstdio>
using namespace std;
int max(int a,int b,int c);
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	float m=1.0*max(a,b,c)/max(a+b,b,c)*max(a,b,b+c);
	printf("%f",m);
	return 0;
} 
int max(int a,int b,int c)
{
	int maxn=a;
	if(b>maxn)maxn=b;
	if(c>maxn)maxn=c;
	return maxn;
}

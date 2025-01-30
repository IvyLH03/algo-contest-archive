#include<cstdio>
using namespace std;
int main()
{
	int sum=0,maxn=0,minn=0,n=0,x;
	float average;
	while(scanf("%d",&x)==1)
	{
		n++;
		sum+=x;
		maxn=maxn>x? maxn:x;
		minn+minn<x? minn:x;
	}
	average=1.0*sum/n;
	printf("%d %d %.3f",minn,maxn,average);
	
	return 0;
}

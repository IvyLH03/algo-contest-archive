#include<cstdio>
using namespace std;
int main()
{
	int n,i;
	float r,x;
	scanf("%f%d",&x,&n);
	for(i=1;i<=n;i+=1)
	{
		r=x+x*0.001;
		x=r;
	}
	printf("%.4f",r);
	return 0;
} 

#include<cstdio>
using namespace std;
int main()
{
	int n,i,j,f=1;
	double e=1;
	scanf("%d",&n);
	for(i=1;i<=n;i+=1)
	{
		for(j=1;j<=i;j+=1)
		{
			f*=j;
		}
		
		e+=1.0/f;
		f=1;
	}
	printf("%.10lf",e);
}

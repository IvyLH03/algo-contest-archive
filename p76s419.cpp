#include<cstdio>
using namespace std;
int main()
{
	int s=0,n,j,i,f=1,y;
	scanf("%d",&n);
	for(i=1;i<=n;i+=1)
	{
		for(j=1;j<=i;j+=1)
		{
			f*=j;
		}
		s+=f;
		f=1;
	}
	y=s%1000000;
	printf("%d",y);
	return 0;
}

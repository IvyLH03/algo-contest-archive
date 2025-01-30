#include<cstdio>
using namespace std;
int main()
{
	int i,j,s=0,x=1;
	for(i=1;i<=10;i+=1)
	{
		for(j=1;j<=i;j+=1)
		{
			x*=j;
			s+=x;
		}
		x=1;
	}
	printf("%d",s);
	
	return 0;
}

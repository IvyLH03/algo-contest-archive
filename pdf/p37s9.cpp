#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,i=3,in,x=2,ord=1,k,s,cin=0;
	scanf("%d",&n);
	for(i=2;;i++)
	{
		while(i%x!=0&&x<ceil(sqrt(i)))
			x++;
		if(i%x!=0&&x>=ceil(sqrt(i)))
			ord++;
		if(ord==n)
		{
			printf("%d",i);
			break;
		}
		x=2;
	}
	return 0;
}

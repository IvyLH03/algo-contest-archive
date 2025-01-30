#include<cstdio>
using namespace std;
int main()
{
	int n,i=0,y=0,in;
	scanf("%d",&n);
	while(n>=0)
	{
		i++;
		in=i;
			if(n<in)
				y+=n*in;
			else
				y+=in*in;
		n-=i;
	}
	printf("%d",y);
	return 0;
}

#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,i=3,x=2,order=1;
	scanf("%d",&n);
	for(i=3;;i++)
	{
		while(x<=floor(sqrt(i))&&i%x!=0)
			x++;
		if(x>floor(sqrt(i)))
			order+=1;
		x=2;
		if(order==n)
			break;
	}
	printf("%d",i);
	return 0;
}

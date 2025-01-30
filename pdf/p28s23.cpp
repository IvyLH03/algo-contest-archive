#include<cstdio>
using namespace std;
int main()
{
	int x,y=0,i;
	scanf("%d",&x);
	for(i=1;i<=x;i+=1)
	{
		y+=i;
	}	
	printf("%d",y);
	
	return 0;
}

#include<cstdio>
using namespace std;
int main()
{
	int m,n,i,x,y=0;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i+=1)
	{
		scanf("%d",&x);
		if(x=m)
			y+=1;
	}
	printf("%d",y);
	
	return 0;
} 

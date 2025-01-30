#include<cstdio>
using namespace std;
int main()
{
	int i,n,j;
	float x,s=1,y=0;
	scanf("%f%d",&x,&n);
	for(i=1;i<=n;i+=1)
	{
		for(j=1;j<=i;j+=1)
		{
			s*=x;
		}
		y+=s;
		s=1;
	}
	printf("%.2f",y+1);
	return 0;
} 

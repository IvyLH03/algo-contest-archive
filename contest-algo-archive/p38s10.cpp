#include<cstdio>
using namespace std;
int main()
{
	int n,y=0,i,s=1;
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=1;i<=s;i++)
		{
			y+=s;
		}
		n-=s;
		s++;
		
	}
	printf("%d",y);
	return 0;
} 

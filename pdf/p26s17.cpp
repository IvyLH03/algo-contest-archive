#include<cstdio>
using namespace std;
int main()
{
	int m,n,i,x,r=0,s;
	scanf("%d%d",&m,&n);
	s=m;
	for(i=1;i<=n;i+=1)
	{
		scanf("%d",&x);
		if(x>s)
			r+=1;
		else
			s=s-x; 
	}
	printf("%d",r);
	
	
	return 0;
} 

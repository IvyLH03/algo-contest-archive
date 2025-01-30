#include<cstdio>
using namespace std;
int main()
{	
	int m,n,r=1,i;
	scanf("%d%d",&m,&n);
	
	for(i=1;i<=n;i+=1)
	{
		r=r*m;
	}
	printf("%d",r);
	
	return 0;
}

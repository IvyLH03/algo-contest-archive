#include<cstdio>
using namespace std;
int main()
{
	int k,n=0;
	float sn=0;
	scanf("%d",&k);
	while(sn<=k)
	{	
		n++;
		sn+=1.0*1/n;
		
	}
	printf("%d",n);
	return 0;
}

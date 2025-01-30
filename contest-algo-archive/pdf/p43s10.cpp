#include<cstdio>
using namespace std;
int a[8],b[8],c[8];
int main()
{
	int i,maxn=0,maxnl=0;
	
	for(i=1;i<=7;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		c[i]=a[i]+b[i];
	}
	
	for(i=1;i<=7;i++)
	{
		if(c[i]>maxn&&c[i]>8)
		{
			maxn=c[i];
			maxnl=i;
		}
		
	}
	printf("%d",maxnl);
	return 0;
}

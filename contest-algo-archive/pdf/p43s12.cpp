#include<cstdio>
using namespace std;
int a[101];
int main()
{
	int n,i,maxn=0,y=0;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxn) maxn=a[i];
	}
	
	for(i=1;i<=n;i++)
		if(a[i]!=maxn)
			y+=a[i];
			
	printf("%d",y);
	
	return 0;
} 

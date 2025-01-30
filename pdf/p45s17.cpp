#include<cstdio>
using namespace std;
int a[10001],b[10001],g[10001],k[10001];
int main()
{
	int n,i,x,y,s=-1;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
		
	scanf("%d%d",&x,&y);
	
	for(i=1;i<=n;i++)
	{
		if(x>=a[i]&&y>=b[i])
			if(x-a[i]<=g[i]&&y-b[i]<=k[i])
				s=i;
	}
	printf("%d",s);
	return 0;
}


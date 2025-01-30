#include<cstdio>
using namespace std;
int a[10001],b[10001];
int main()
{
	int n,i,maxn=0,s=0,j;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxn) maxn=a[i];	
	}
	
	for(i=0;i<=maxn;i++)
	{
		for(j=1;j<=n;j++)
			if(a[j]==i) b[i]++;
	}
	
	for(j=0;j<=maxn;j++)
		printf("%d\n",b[j]);
	return 0;
}

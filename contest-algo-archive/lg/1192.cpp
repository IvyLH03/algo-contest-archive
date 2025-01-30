#include<cstdio>
using namespace std; 
int a[100001],k,n;
int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	a[0]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=k&&i-j>=0;j++)
		{
			a[i]+=a[i-j];
			a[i]%=100003;
		}
	printf("%d",a[n]);
	return 0;
	 
}

#include<cstdio>
using namespace std;
bool a[10000001];
int main()
{
	int n,ans=1;
	scanf("%d",&n);
	a[1]=1;
	long long i,j;
	for(i=2;i*i<=n;i++)
	{
		for(j=i*i;j<=n;j*=i)
		{
			if(!a[j])
			{
				a[j]=1;ans++;
			}
		} 
	} 
		
	printf("%d",ans);
	return 0;
} 

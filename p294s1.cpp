#include<cstdio>
#include<iostream>
using namespace std;
int k,n[201],res[201];
int main()
{
	scanf("%d",&k);
	int r=1;
	for(int i=1;i<=k;i++)
	{
		r=1;
		scanf("%d",&n[i]);
		for(int j=1;j<=n[i];j++)
		{
			r*=2011;
			r%=10000;
			//	printf("  j=%d,r=%d\n",j,r);
		}
		res[i]=r;
	}
	for(int i=1;i<=k;i++)
		printf("%d\n",res[i]);
	return 0;
}

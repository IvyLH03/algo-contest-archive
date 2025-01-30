#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,f[20001],w[31];
int main()
{
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(i=1;i<=n;i++)
		for(j=m;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+w[i]);
	printf("%d",m-f[m]);
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,f[1001],w[101],v[101];
int main()
{
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d%d",&w[i],&v[i]);
		
	for(i=1;i<=n;i++)
		for(j=m;j>=w[i];j--)
			f[j]=max(f[j-w[i]]+v[i],f[j]);
	printf("%d",f[m]);
	return 0;
}

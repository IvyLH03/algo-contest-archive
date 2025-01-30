#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,f[100001],v[10001],w[10001];
int main()
{
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d%d",&w[i],&v[i]);
	for(i=1;i<=n;i++)
		for(j=w[i];j<=m;j++)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
	printf("%d",f[m]);
	return 0;
}

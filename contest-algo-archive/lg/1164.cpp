#include<cstdio>
using namespace std; 
int f[10001],n,m,v[101];
int main()
{
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	f[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=m;j>=v[i];j--)
			f[j]+=f[j-v[i]];
	}
	printf("%d",f[m]);
	return 0;
}

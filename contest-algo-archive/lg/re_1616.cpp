//luogu P1616 疯狂的采药（完全背包模板） 
#include<cstdio>
using namespace std;
int t,m,w[10001],v[10001],f[100001];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j;
	scanf("%d%d",&t,&m);
	for(i=1;i<=m;i++)
		scanf("%d%d",&w[i],&v[i]);
	
	for(i=1;i<=m;i++)
		for(j=w[i];j<=t;j++)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
	
	printf("%d",f[t]);
	return 0;
}

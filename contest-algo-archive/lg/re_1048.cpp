//luogu P1048≤…“© 
#include<cstdio>
using namespace std;
int t,m,w[101],v[101],f[1001];
int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	int i,j;
	scanf("%d%d",&t,&m);
	for(i=1;i<=m;i++)
		scanf("%d%d",&w[i],&v[i]);
		
	for(i=1;i<=m;i++)
		for(j=t;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
			
	printf("%d",f[t]);
	return 0;
}

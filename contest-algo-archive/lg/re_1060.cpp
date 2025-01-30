//luogu P1060开心的金明
#include<cstdio>
using namespace std;
int m,n,f[30007],w[26],v[26];
int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int i,j,a;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&w[i],&a);
		v[i]=w[i]*a;
	}
	for(i=1;i<=n;i++)
		for(j=m;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
			
	printf("%d",f[m]);
	return 0;
} 

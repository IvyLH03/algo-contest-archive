//lg P2677 ≥¨º∂ Èº‹2
#include<cstdio>
using namespace std;
int n,b,m,w[27],h,f[20000007];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&b);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		h+=w[i];
	}
	m=h-b;
	//printf("m=%d ",m);
	for(i=1;i<=n;i++)
		for(j=m;j>=w[i];j--)
			if(f[j-w[i]]+w[i]<=m)
				f[j]=max(f[j],f[j-w[i]]+w[i]);
	
	printf("%d",m-f[m]);
	return 0;
} 

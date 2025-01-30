//luogu P1776 宝物筛选（多重背包优化） 
#include<cstdio>
using namespace std;
int n,m,v[1001],w[1001],f[40001],a,s,x,y;
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j=0,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&a);
		s=1;
		while(a>=s)
		{
			v[++j]=x*s;w[j]=y*s;
			a-=s;s*=2;
		}
		v[++j]=x*a;w[j]=y*a;
	}
	n=j;
	
	for(i=1;i<=n;i++)
		for(j=m;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
			
	printf("%d",f[m]);
	return 0;
}

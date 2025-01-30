//luogu 1064依赖背包(修改后的分组，部分WA/TLE) 
#include<cstdio>
#include<cstring>
using namespace std;
int m,n,w[67],v[67],q[67],f[32007],g[32007];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j,k,ii,p;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&w[i],&p,&q[i]);
		v[i]=w[i]*p;
	}
	for(i=1;i<=n;i++)
	{
		if(q[i]) continue;
		k=0;memset(g,0,sizeof(g));
	
		for(j=1;j<=n;j++)
		{
			if(k==2)break;
			if(q[j]==i)
			{
				k++;
				for(ii=m-w[i];ii>=w[ii];ii--)
					g[ii]=max(g[ii],g[ii-w[ii]]+v[ii]);
			}
		}
		if(!k)
		{
			for(j=m;j>=w[i];j--)
				f[j]=max(f[j],f[j-w[i]]+v[i]);
			continue;
		}
		for(j=m;j>=w[i];j--)
		{
			for(k=0;k<=j-w[i];k++)
				f[j]=max(f[j],f[j-w[i]-k]+g[k]+v[i]);
		}
	}
	printf("%d",f[m]);
	return 0;
}

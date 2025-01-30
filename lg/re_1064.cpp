//luogu 1064ÒÀÀµ±³°ü(²¿·ÖTLE) 
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
	int i,j,k,p,ww[3],vv[3];
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&w[i],&p,&q[i]);
		v[i]=w[i]*p;
	}
	for(i=1;i<=n;i++)
	{
		if(q[i]) continue;
		k=1;memset(g,0,sizeof(g));
		ww[1]=ww[2]=vv[1]=vv[2]=0;
		for(j=1;j<=n;j++)
		{
			if(k==3)break;
			if(q[j]==i)
			{
				ww[k]=w[j];vv[k]=v[j];k++;
			}
		}
		k--;
		if(!k)
		{
			for(j=m;j>=w[i];j--)
				f[j]=max(f[j],f[j-w[i]]+v[i]);
			continue;
		}
		while(k)
		{
			for(j=m-w[i];j>=ww[k];j--)
				g[j]=max(g[j],g[j-ww[k]]+vv[k]);
			k--;
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

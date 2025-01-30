//luogu P1782 旅行商的背包 
#include<cstdio>
using namespace std;
int n,m,maxm,v[10007],w[10007],a[6],b[6],c[6],f[1000007];
	
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j=0,k,x,y,d,s;
	scanf("%d%d%d",&n,&m,&maxm);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&d);
		s=1;
		while(d>=s)
		{
			v[++j]=x*s;w[j]=y*s;
			d-=s;s*=2;
		}
		v[++j]=x*d;w[j]=y*d;
	}
	n=j;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
		
	for(i=1;i<=n;i++)
		for(j=maxm;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
			
	int t,ans=0;
	for(i=1;i<=maxm;i++)
		if(f[i]>ans)
		{
			ans=f[i];t=i;		//t:已用容量 
		}
						//	printf("\n多：%d\n",ans);
	
	for(i=1;i<=m;i++)
		for(j=maxm;j>=0;j--)
			for(k=0;k<=j;k++)
				{
					f[j]=max(f[j],f[j-k]+(a[i]*k*k+b[i]*k+c[i]));  //printf("%d ",f[j]);
				}
				
	
	printf("%d",f[maxm]);
	return 0;	
	
	
}

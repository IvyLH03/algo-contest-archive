#include<cstdio>
using namespace std;
long long f[10007];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n,m,c,x,y,z,i,j,k=0,s,w,v;
	scanf("%d%d%d",&n,&m,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);//体积，价值，数量 
		if(x*z>c)//完全背包 
		{
			for(j=x;j<=c;j++)
				f[j]=max(f[j],f[j-x]+y);
		}
		else//多重背包 
		{
			s=1;
			while(z>=s)
			{
				w=x*s;v=y*s;
				z-=s;s*=2;
				for(j=c;j>=w;j--)
					f[j]=max(f[j],f[j-w]+v);
			}
			if(z)
			{
				w=x*z;v=y*z; 
				for(j=c;j>=w;j--)
					f[j]=max(f[j],f[j-w]+v);
			}
		}
	}
	
	int t,maxn=0;
	for(i=1;i<=c;i++)
		if(f[i]>maxn)
		{
			 t=i;maxn=f[i];
		}
	
	for(i=1;i<=m;i++) //奇货  
	{
		scanf("%d%d%d",&x,&y,&z);
		for(j=c;j>=0;j--)
			for(k=0;k<=j;k++)
				f[j]=max(f[j],f[j-k]+x*k*k+y*k+z);
	}
	
	printf("%lld",f[c]);
	return 0;
}

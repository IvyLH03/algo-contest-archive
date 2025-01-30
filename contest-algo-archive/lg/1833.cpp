#include<cstdio>
using namespace std;
int m,n,f[10001];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int w,v,t,a,b,c,d,i,j,s,ww,vv;
	scanf("%d:%d",&a,&b);
	c=a*60+b;
	scanf("%d:%d",&a,&b);
	d=a*60+b;
	m=d-c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&w,&v,&t);
		if(!t) //完全
		{
			for(j=w;j<=m;j++)
				f[j]=max(f[j],f[j-w]+v);
		}
		else  
		{
			if(t==1) //01 
			{
				for(j=m;j>=w;j--)
					f[j]=max(f[j],f[j-w]+v);
			}
			else	//多重 
			{
				s=1;
				while(t>=s)
				{
					ww=w*s;vv=v*s;
					for(j=m;j>=ww;j--)
						f[j]=max(f[j],f[j-ww]+vv);
					t-=s;s*=2;
				}
				ww=w*t;vv=v*t;
				for(j=m;j>=ww;j--)
					f[j]=max(f[j],f[j-ww]+vv);
			}
		}
		
	}
	printf("%d",f[m]);
	return 0;
}

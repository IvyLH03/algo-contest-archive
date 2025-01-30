#include<cstdio>
#include<cstring>
using namespace std;
int t,n,w[10007],m,ans;
double v[10007],f[10007],p;
double max(double a,double b)
{
	return a>b?a:b;
}
int main()
{
	int iiiii,i,j;
	scanf("%d",&t);
	for(iiiii=1;iiiii<=t;iiiii++)
	{
		memset(f,0,sizeof(f));
		scanf("%lf%d",&p,&n);
		p=1-p; m=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%lf",&w[i],&v[i]);
			v[i]=1-v[i];
			m+=w[i];
		}
		f[0]=1;
		for(i=1;i<=n;i++)
			for(j=m;j>=w[i];j--)
				f[j]=max(f[j],f[j-w[i]]*v[i]);
		
		ans=0;
		for(i=1;i<=m;i++)
		{
			if(f[i]>p&&i>ans) ans=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}

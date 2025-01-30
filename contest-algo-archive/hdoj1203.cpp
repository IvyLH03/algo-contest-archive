//hdu 1203
#include<cstdio>
#include<cstring>
using namespace std;
int m,n,w[10007];
double f[10007],v[10007],ans;
double min(double a,double b)
{
	return a<b?a:b;
} 
int main()
{
	int i,j,k;
	scanf("%d%d",&m,&n);
	while(n||m)
	{
		for(i=0;i<=m;i++)
			f[i]=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d%lf",&w[i],&v[i]);
			v[i]=1-v[i];
		} 
		
		for(i=1;i<=n;i++)
			for(j=m;j>=w[i];j--)
				f[j]=min(f[j],f[j-w[i]]*v[i]);
				
		ans=(1-f[m])*100;
		printf("%.1lf%%\n",ans);
		
		
		scanf("%d%d",&m,&n);
	}
	return 0;
}

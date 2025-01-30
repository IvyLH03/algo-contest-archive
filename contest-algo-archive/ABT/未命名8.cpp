//luogu P1782 旅行商的背包 
#include<cstdio>
using namespace std;
int n,m,maxm,v[10007],w[10007],a[6],b[6],c[6];
int fv(int num,int spc)
{
	if(num<=n)
		return v[num];
	num-=n;
	return a[num]*spc*spc+b[num]*spc+c[num];
}
int main()
{
	int i,j=0,k,x,y,d;
	scanf("%d%d%d",&n,&m,&maxm);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&d);
		s=1;
		while(a>=s)
		{
			v[++j]=x*s;w[j]=y*s;
			a-=s;s*=2;
		}
		v[++j]=x*a;w[j]=y*a;
	}
	n=j;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		w[i+n]=0; 
	}
		
	for(i=1;i<=n+m;i++)
		for(j=maxm;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]])
			
	
	
}

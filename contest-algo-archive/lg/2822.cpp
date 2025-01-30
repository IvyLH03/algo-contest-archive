#include<cstdio>
using namespace std;
int p[2007],c[2007][2007],t,k,n,m;
int jc(int n)
{
	if(p[n]) return p[n];
	if(n==1) return 1;
	p[n]=n*jc(n-1);return p[n];
}
int main()
{
	int i,j,ans;
	scanf("%d%d",&t,&k);
	while(t--)
	{
		ans=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=i&&j<=m;j++)
			{
				if(c[i][j])
				{
					if(!(c[i][j]%k)) ans++;
					break;
				}
				c[i][j]=jc(i)/(jc(j)*jc(i-j));
				if(!(c[i][j]%k)) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

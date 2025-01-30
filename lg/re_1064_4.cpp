//luogu P1064
#include<cstdio>
using namespace std;
int f[32007],n,m,w[67][3],v[67][3],p[67][32007],d[67][32007],g[32007],num[67];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	scanf("%d%d",&m,&n);
	int i,j,k,a,b,c,q;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(!c)
		{
			w[i][0]=a;v[i][0]=a*b;
		}
		else
		{				
			if(w[c][1]||v[c][1])
			{
				w[c][2]=a;v[c][2]=a*b;
			}
			else
			{
				w[c][1]=a,v[c][1]=a*b;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(w[i][0]||v[i][0])
		{							
			if(w[i][1]||v[i][1])
			{						
				for(j=1;j<=m;j++)
					g[j]=10000001;
				g[0]=0;
				for(j=1;j<=2;j++)
				{
					if(w[i][j])
						for(k=m-w[i][0];k>=w[i][j];k--)
							if(g[k-w[i][j]]!=10000001)
								g[k]=max(g[k],g[k-w[i][j]]+v[i][j]);
				}
				num[i]=0;
				for(j=0;j<=m-w[i][0];j++)
				{
					if(g[j]!=10000001)
					{
						p[i][++num[i]]=g[j]+v[i][0];
						d[i][num[i]]=j+w[i][0];
					}
				}
				
				
			}
		
			else
			{
				num[i]=1;
				p[i][1]=v[i][0];d[i][1]=w[i][0];
			}
		}
	}
	
	
	for(i=1;i<=n;i++)
	{ 
		if(w[i][0]||v[i][0])
			for(j=m;j>=w[i][0];j--)
				for(k=1;k<=num[i];k++)
					if(j>=d[i][k])
						f[j]=max(f[j],f[j-d[i][k]]+p[i][k]);
	} 
	
	
	printf("%d",f[m]);
	return 0;
}


#include<cstdio>
#include<cstring> 
using namespace std;
int f[201][201],t[201];
int main()
{
	int n,m,q,a,b,w,i,j,k,x,y,tt,s,kt=0;

	scanf("%d%d",&n,&m);

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			f[i][j]=1000000;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&t[i]);
		f[i][i]=0;
	}

	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		f[a][b]=f[b][a]=w;
	}
	
	scanf("%d",&q);
	for(s=1;s<=q;s++)
	{
		scanf("%d%d%d",&x,&y,&tt);
		
		while(t[kt]<=tt&&kt<n)
		{
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(f[i][j]>f[i][kt]+f[kt][j])
						f[i][j]=f[j][i]=f[i][kt]+f[kt][j];
			kt++;
		}
							
		if(f[x][y]==1000000||t[x]>tt||t[y]>tt)
			printf("-1\n");
		else
			printf("%d\n",f[x][y]); 
	}
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;
const int N=207,maxn=10007;
int f[N][maxn],n,m,t,d[N],p[N];
bool vis[N][maxn][N];
int abs(int x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%d%d",&n,&m);
	while(n)
	{
		t++;int sum=0;
		memset(f,-1,sizeof(f));
		for(int i=1;i<=n;i++) 
		{
			scanf("%d%d",&d[i],&p[i]);
			if(f[1][400+d[i]-p[i]]<d[i]+p[i])
			{
				for(int j=1;j<=n;j++) vis[1][400+d[i]-p[i]][j]=0;
				f[1][400+d[i]-p[i]]=d[i]+p[i];
				vis[1][400+d[i]-p[i]][i]=1;
			}
		}
		sum=800;
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=2;j--)
			{
				
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=sum;j++)
				if(f[i][j]>0) 
				{
					printf("f[%d][%d]=%d ",i,j,f[i][j]);
					for(int k=1;k<=n;k++) if(vis[i][j][k]) printf("%d ",k);
					printf("\n");
				}
		}
		int sumd=0,sump=0,ans;
		for(int i=0;i<=400;i++)
		{
			if(f[m][400-i]>f[m][400+i]) 
			{
				ans=400-i;break;
			}
			else if(f[m][400-i]<f[m][400+i]!=-1||(f[m][400-i]!=-1&&f[m][400+i]!=-1))
			{
				ans=400+i;break;
			}
		}
		for(int i=1;i<=n;i++)
			if(vis[m][ans][i]) 
				sumd+=d[i],sump+p[i]; 
		printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",t,sump,sumd);
		for(int i=1;i<=n;i++)
			if(vis[m][ans][i]) printf(" %d",i);
		printf("\n");
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
	}
}

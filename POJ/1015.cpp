#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=207,MaxN=807;
int f[N][MaxN],n,m,sumd,p[N],d[N],t;
bool vis[N][N][MaxN];
int main()
{
	
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(!n) break;
		t++;
		memset(vis,0,sizeof(vis));
		sumd=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&d[i],&p[i]);
			sumd+=d[i];
		}
	//	for(int i=1;i<=m;i++)
	//		for(int j=1;j<=sumd;j++)
	//			f[i][j]=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=1;j--)
				for(int k=d[i];k<=sumd;k++)
				{
			//		if(f[j-1][k-d[i]]!=-1&&(abs(k-d[i]-p[i])<abs(k-f[j][k])||f[j][k]==-1||((abs(k-d[i]-p[i])==abs(k-f[j][k]))&&k-d[i]+p[i]>k+f[j][k])))
					if((abs(k-d[i]-p[i])<abs(k-f[j][k])||f[j][k]==0||((abs(k-d[i]-p[i])==abs(k-f[j][k]))&&k-d[i]+p[i]>k+f[j][k])))
					{
						f[j][k]=f[j-1][k-d[i]]+p[i];
						memcpy(vis[j][k],vis[j-1][k-d[i]],sizeof(vis[j-1][k-d[i]]));
						vis[j][k][i]=1;
					}
				}
		} 
		int tot=100010,sum=0,ans;
		for(int i=1;i<=sumd;i++)
		{
			if(abs(i-f[m][i])<tot||(abs(i-f[m][i])==tot&&i+f[m][i]>sum))
			{
				tot=abs(i-f[m][i]);ans=i;sum=i+f[m][i];
			}
		}
		printf("%d",tot);
	}
}

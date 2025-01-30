#include<cstdio>
#include<algorithm>
using namespace std;
int dis[10001][10001];
bool flag[10001];
int main()
{
	int n,m,s,i,j,k,a,b,c,minn=10000001,u;
	scanf("%d%d%d",&n,&m,&s);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j) dis[i][j]=10000001;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		dis[a][b]=c;
	}
	flag[s]=1;
	for(i=1;i<=n-1;i++)
	{
		minn=10000001; 
		for(j=1;j<=n;j++)
			if(dis[s][j]<minn&&(!flag[j]))
			{
				minn=dis[s][j];
				u=j;
			}
		flag[u]=1;
		for(j=1;j<=n;j++)
			if(dis[u][j]<10000001)
				dis[s][j]=min(dis[s][j],dis[s][u]+dis[u][j]);
	}
	if(s==1)
			printf("0");
		else
		{
			if(dis[s][1]!=10000001)
				printf("%d",dis[s][1]);
			else
				printf("2147483647");
		}
	for(i=2;i<=n;i++)
	{
		if(i==s)
			printf(" 0");
		else
		{
			if(dis[s][i]!=10000001)
				printf(" %d",dis[s][i]);
			else
				printf(" 2147483647");
		}
	}
	return 0;
	
} 

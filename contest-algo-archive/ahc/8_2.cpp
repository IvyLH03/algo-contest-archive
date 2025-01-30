#include<cstdio>
using namespace std;
int e[5005][5005],dis[5005];
const int inf=20000001;
bool flag[5005],flag2;
int main()
{
	int n,m,i,j,k,a,b,c,minn,s;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			e[i][j]=inf;
			
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c<e[a][b])
			e[a][b]=e[b][a]=c;
	}
	for(i=1;i<=n;i++)
		e[i][i]=0; 
	for(i=2;i<=n;i++)
		dis[i]=e[1][i];
					//	for(i=1;i<=n;i++)
					//		printf("%d ",dis[i]);
					//	printf("\n\n");	
					//	for(i=1;i<=n;i++)
					//	{
					//	for(j=1;j<=n;j++)
					//		if(e[i][j]<inf)	
					//			printf("%10d",e[i][j]);
					//		else
					//			printf("       inf");
					//		printf("\n");
					//	}
									
	flag[1]=1;
	for(k=1;k<n;k++)
	{
		minn=inf;
		for(i=2;i<=n;i++)
			if(dis[i]<minn&&(!flag[i]))
			{       //		printf(".");
				minn=dis[i];
				s=i;
			}
		flag[s]=1;
		for(i=1;i<=n;i++)
			if(dis[i]>e[s][i]&&(!flag[i]))
				dis[i]=e[s][i];
	}
	
	int ans=0;
	for(i=1;i<=n;i++)
	{
		if(dis[i]==inf)
		{
			flag2=1;break;
		}
		ans+=dis[i];
	}
					//	printf("\n");
					//	for(i=1;i<=n;i++)
					//		printf("%d ",dis[i]);
					//	printf("\n");
	if(flag2) printf("orz");
	else 	  printf("%d",ans);
	return 0;
}

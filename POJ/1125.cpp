#include<cstdio>
#include<cstring>
using namespace std;
int dis[105][105];
int main()
{
	int n,m,a,b,c,i,j,k;
	scanf("%d",&n);
	while(n)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				dis[i][j]=2147483647;
			dis[i][i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			for(j=1;j<=a;j++)
			{
				scanf("%d%d",&b,&c);
				dis[i][b]=c;
			}
		}	
									//	for(i=1;i<=n;i++)
									//	{
									//		for(j=1;j<=n;j++)
									//			printf("%15d",dis[i][j]);
									//		printf("\n");
									//	}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(dis[i][j]>dis[i][k]+dis[k][j]&&dis[i][k]!=2147483647&&dis[k][j]!=2147483647)
						dis[i][j]=dis[i][k]+dis[k][j];
		
										//for(i=1;i<=n;i++)
										//{
										//	for(j=1;j<=n;j++)
										//		printf("%d ",dis[i][j]);
										//	printf("\n");
										//}
		
		
							
		int minn=2147483647,u,ls=0;
		for(i=1;i<=n;i++)
		{
			ls=0;
			for(j=1;j<=n;j++)
			{
				if(dis[i][j]==2147483647)
				{
					ls=0;
					break;
				}
				if(dis[i][j]>ls)
					ls=dis[i][j];
			}
			
			if(ls<minn&&ls)
			{
				minn=ls;
				u=i;
			}
		}
		if(ls!=2147483647)
			printf("%d %d\n",u,minn);
		else
			printf("disjoint\n");
		scanf("%d",&n);
	}
	return 0;
}

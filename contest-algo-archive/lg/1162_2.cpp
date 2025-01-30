#include<cstdio>
using namespace std;
int n,a[31][31],
	dx[4]={1,-1,0,0},
	dy[4]={0,0,1,-1},
	que[901][3]; 
bool bz[31][31];
void bfs(int ax,int ay)
{
	int x,y,i,t=1,w=1;
	que[1][1]=ax;
	que[1][2]=ay;
	while(t<=w)
	{
		for(i=0;i<=3;i++)
		{
			x=que[t][1]+dx[i];
			y=que[t][2]+dy[i];
			if(x>0&&x<=n&&y>0&&y<=n&&(!bz[x][y])&&(!a[x][y]))
			{
				w++;
				que[w][1]=x;
				que[w][2]=y;
				bz[x][y]=1;
			}
		}
		t++;
	}
}
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=1;i<=n;i++)
	{
		if((!bz[1][i])&&(!a[1][i]))
			bfs(1,i);
		if((!bz[n][i])&&(!a[n][i]))
			bfs(n,i);
		if((!bz[i][1])&&(!a[i][1]))
			bfs(i,1);
		if((!bz[i][n])&&(!a[i][n]))
			bfs(i,n);
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if((!bz[i][j])&&(!a[i][j]))
				printf("2 ");
			else printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
} 

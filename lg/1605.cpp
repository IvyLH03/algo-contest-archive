#include<cstdio>
using namespace std;
int tot,m,n,t,ax,ay,bx,by;
int dx[4]={1,-1,0,0},
	dy[4]={0,0,1,-1};
bool bz[6][6];
int search(int ax,int ay)
{
	int i,x,y;
	for(i=0;i<=3;i++)
	{
		x=ax+dx[i];y=ay+dy[i];
		if(x>0&&x<=m&&y>0&&y<=n&&(!bz[x][y]))
		{
			bz[x][y]=1;
			if(x==bx&&y==by)tot++;
			else search(x,y);
			bz[x][y]=0;
		}
	}
}
int main()
{
	int i,tx,ty;
	scanf("%d%d%d%d%d%d%d",&m,&n,&t,&ax,&ay,&bx,&by);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&tx,&ty);
		bz[tx][ty]=1;
	}
	bz[ax][ay]=1;
	search(ax,ay);
	printf("%d",tot);
	return 0;
}

#include<cstdio>
using namespace std;
int n,dt[31][31],que[901][3],qy[901],nm;
int dx[4]={0,1,0,-1},
	dy[4]={1,0,-1,0};
bool bz[31][31];
void search(int ax,int ay)
{
	bz[ax][ay]=1;
	int x,y,t=1,w=1,i;
	que[t][1]=ax;
	que[t][2]=ay;
	while(t<=w)
	{
		for(i=0;i<=3;i++)
		{
			x=que[t][1]+dx[i];
			y=que[t][2]+dy[i];
			if(x>=0&&x<n&&y>=0&&y<n&&(!bz[x][y])&&(!dt[x][y]))
			{
				w++;
				bz[x][y]=1;
				que[w][1]=x;
				que[w][2]=y;
			}
		} 
		t++;
	}
}
int main()
{
	int i,j;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&dt[i][j]);
	for(i=0;i<n;i++)
	{
		if((!bz[0][i])&&(!dt[0][i]))
			search(0,i);
	}
	for(i=1;i<n-2;i++)
	{
		if((!bz[i][0])&&(!dt[i][0]))
			search(i,0);
		if((!bz[i][n-1])&&(!dt[i][n-1]))
			search(i,n-1);
	}
	for(i=0;i<n;i++)
	{
		if((!bz[n-1][i])&&(!dt[n-1][i]))
			search(n-1,i);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if((!bz[i][j])&&(!dt[i][j]))
				printf("2 ");
			else if((bz[i][j])&&(!dt[i][j]))
				printf("0 ");
			if((dt[i][j]))
				printf("1 ");
		}
		if(dt[i][j])printf("1\n");
		else printf("0\n");
	}
	return 0;
		
}


#include<cstdio>
using namespace std;
int maze[5][5],que[25][4],sc[25][3];
int dx[4]={1,-1,0,0},
	dy[4]={0,0,1,-1};
int main()
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&maze[i][j]);
	int x,y,t=1,w=1;
	que[1][1]=0;que[1][2]=0;que[1][3]=0;
	while(t<=w)
	{
		for(i=0;i<=3;i++)
		{
			x=que[t][1]+dx[i];
			y=que[t][2]+dy[i];
			if((x>=0)&&(x<5)&&(y>=0)&&(y<5)&&(maze[x][y]==0))
			{//printf("."); 
				w++;
				que[w][1]=x;que[w][2]=y;
				que[w][3]=t;
				maze[x][y]=1;
				if(x==4&&y==4)
				{//printf(".");
					sc[1][1]=4;
					sc[1][2]=4;
					int r=que[w][3],k=1;
					while(r!=0)
					{
						k++;
						sc[k][1]=que[r][1];
						sc[k][2]=que[r][2];
						r=que[r][3];
					}
					
					for(j=k;j>=1;j--)
						printf("(%d,%d)\n",sc[j][1],sc[j][2]);
					return 0;
				}
			}
		}
		t++;
	}
	return 0;
} 

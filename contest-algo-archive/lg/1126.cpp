#include<cstdio>
#include<cmath>
int m,n,dt[51][51],ax,ay,bx,by,que[2501][4];
bool bz[51][51];
int dx[4][5]={{-1,-2,-3,0,0},{0,0,0,0,0},{1,2,3,0,0},{0,0,0,0,0}},
	dy[4][5]={{0,0,0,0,0},{-1,-2,-3,0,0},{0,0,0,0,0},{1,2,3,0,0}},
	dd[5]={0,0,0,1,-1};
						//creep,walk,run,left,right
						//que[][3]%4==0,N
						//			==1,W
						//			==2,S
						//			==3,E
char ad;
int abs(int a)
{
	if(a<0)return a*-1;
	else return a;
}
void search()
{
	int x,y,d,t=1,w=1,i;
	while(t<=w)
	{
		for(i=0;i<=4;i++)
		{
			d=abs(que[t][3]+dd[i])%4;
			x=que[t][0]+dx[d][i]; 
			y=que[t][1]+dy[d][i];
			if(x>0&&y>0&&x+1<=m&&y+1<=n&&(!bz[x][y])
				&&(!dt[x][y])&&(!dt[x+1][y])&&(!dt[x][y+1])
				&&(!dt[x+1][y+1]))
			{		printf("(%d,%d),d=%d\n",x,y,d);
				w++;
				bz[x][y]=1;
				que[w][0]=x;
				que[w][1]=y;
				que[w][2]=que[t][2]+1;
				que[w][3]=d;
				if(x==bx&&y==by)
				{
					printf("%d",que[w][2]);
					return;
				}
			}
		}
		t++; 
	}
}
int main()
{
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&dt[m][n]);
	scanf("%d%d%d%d %c",&ax,&ay,&bx,&by,&ad);
	que[1][0]=ax;
	que[1][1]=ay;
	que[1][2]=0;
	switch(ad)
	{
		case 'N':{que[1][3]=0;
			break;
		}
		case 'W':{que[1][3]=1;
			break;
		}
		case 'S':{que[1][3]=2;
			break;
		}
		case 'E':{que[1][3]=3;
			break;
		}
	}
	search();
	return 0;
}

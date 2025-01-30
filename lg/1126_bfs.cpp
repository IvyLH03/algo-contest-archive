#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int que[250001][4],m,n,ax,ay,bx,by,minn=100001;//que0:x;
bool dt[51][51];				   //que1:y;
int dd[5][2]={{0,0},{-1,0},{0,1},{1,0},{0,-1}},bs[51][51],rs[100001],rst;
char ad;						   //que2:step;
int main()						   //que3:dir;
{									  //1-N;
	memset(bs,1,sizeof(bs));	//	printf("%d",bs[1][1]);
	int i,j;						  //2-E;
	bool a;							  //3-S;
	scanf("%d%d",&m,&n)	;			  //4-W;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a);
			if(a)
			{
				dt[i][j]=1;
				dt[i-1][j]=1;
				dt[i][j-1]=1;
				dt[i-1][j-1]=1;
			}
		}
	scanf("%d%d%d%d %c",&ax,&ay,&bx,&by,&ad); 
	
	switch(ad)
	{
		case 'N':{
			que[1][3]=1;break;
		}
		case 'E':{
			que[1][3]=2;break;
		}
		case 'S':{
			que[1][3]=3;break;
		}
		case 'W':{
			que[1][3]=4;break;
		}
	}
	int t=1,w=1,x,y,step=0;//x,y,stepÎªÁÙÊ±(FULL) 
	que[1][0]=ax;
	que[1][1]=ay;
	que[1][2]=0;
//	bs[ax][ay]=0;
	while(t<=w)
	{
		if(que[t][0]==bx&&que[t][1]==by)
		{
			rs[++rst]=que[t][2];
		}
		for(i=1;i<=4;i++)
		{
			step=que[t][2];
			if(i!=que[t][3])
			{
				step++;
				if((i==1&&que[t][3]==3)||(i==3&&que[t][3]==1)
				||(i==2&&que[t][3]==4)||(i==4&&que[t][3]==2))
					step++;//printf("7.");
			}			
			for(j=1;j<=3;j++)
			{
				x=que[t][0]+j*dd[i][0];
				y=que[t][1]+j*dd[i][1];
				if(x<1||x>m||y<1||y>n||dt[x][y])
					break;
				if(step<bs[x][y])
				{//printf("t(%d,%d),d=%d;n(%d,%d),d=%d,step=%d\n",que[t][0],que[t][1],que[t][3],x,y,i,step+1);
					w++;
					que[w][0]=x;
					que[w][1]=y;
					que[w][2]=step+1;
					que[w][3]=i;
					bs[x][y]=step;
					//if(x==bx&&y==by)
					//{//printf("7.");
					//	if(que[w][2]<minn)
					//		minn=que[w][2];
					//}
				}
			}
		}
		t++;
	}
	for(i=1;i<=rst;i++)
		if(rs[i]<minn)
			minn=rs[i];
	if(minn==100001)printf("-1");
	else printf("%d",minn);
	return 0;
}

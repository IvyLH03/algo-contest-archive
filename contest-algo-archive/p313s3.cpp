#include<cstdio>
using namespace std;
int dz[100][100],qi[100][100][5],que[10000][3],num,maxn,m,n,s[100][100]={0};
int dx[4]={1,-1,0,0},//¡ý¡ü¡ú¡û 
	dy[4]={0,0,1,-1};
void doit(int p,int q)
{
	num++; 
	int x,y,i,t=1,w=1;
	que[1][1]=p;que[1][2]=q;s[p][q]=1;
	while(t<=w)
	{
		for(i=0;i<=3;i++)
		{
			x=que[t][1]+dx[i];
			y=que[t][2]+dy[i];
			int xx=que[t][1],yy=que[t][2];
			if((qi[xx][yy][i]==0)&&(s[x][y]==0)&&(x>0)&&(x<=m)&&(y>0)&&(y<=n))
			{	//	printf("x=%d y=%d\n",x,y);
				w++;
				que[w][1]=x;
				que[w][2]=y;
				s[x][y]=1;
			}
		}
		t++;
	}
	if(w>maxn)maxn=w;
}
int main()
{
	int i,j;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&dz[i][j]);
			qi[i][j][0]=dz[i][j]/8;dz[i][j]%=8;	//¡ý 
			qi[i][j][2]=dz[i][j]/4;dz[i][j]%=4;	//¡ú 
			qi[i][j][1]=dz[i][j]/2;dz[i][j]%=2;	//¡ü 
			qi[i][j][3]=dz[i][j];			//¡û 
		}
	//	printf(".");
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(s[i][j]==0)
				{doit(i,j);//printf("i=%dj=%d\n",i,j);
				}
	//	printf(".");	
	printf("%d\n%d",num,maxn);
	return 0;
}


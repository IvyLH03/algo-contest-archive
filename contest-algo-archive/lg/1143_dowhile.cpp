#include<cstdio>
using namespace std;
int n,m,ax,ay,dt[401][401],que[160001][3],
    dx[8]={-2,-2,-1,1,2,2,1,-1},
    dy[8]={-1,1,2,2,1,-1,-2,-2};
bool bz[401][401];
int search(int ax,int ay)
{
    int t=1,w=1,x,y,i;
    que[1][0]=ax;
    que[1][1]=ay;
    que[1][2]=0;
    do
    {
        for(i=0;i<=7;i++)
        {
            x=que[t][0]+dx[i];
            y=que[t][1]+dy[i];
            if(x<=m&&x>0&&y<=n&&y>0&&(!bz[x][y]))
            {
                w++;
                bz[x][y]=1;
                que[w][0]=x;
                que[w][1]=y;
                que[w][2]=que[t][2]+1;
                dt[x][y]=que[w][2];
            }
        }
        t++;
    }while(t<w);
}
int main()
{
    scanf("%d%d%d%d",&m,&n,&ax,&ay);
    bz[ax][ay]=1;
    search(ax,ay);
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            if((!dt[i][j])&&(!bz[i][j]))
                printf("%-5d",-1);
            else
                printf("%-5d",dt[i][j]);
        printf("\n");
    }
    return 0;
}

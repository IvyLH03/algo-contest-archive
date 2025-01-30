#include<cstdio>
using namespace std;
int rk[3],ck[3],bz[101][101],que[10001][4];
int dx[4]={1,-1,0,0},
	dy[4]={0,0,1,-1};
char s[101];
int main()
{
	int m,n,i,j;
	scanf("%d%d\n",&m,&n);
	for(i=0;i<m;i++)
	{
		gets(s);
		for(j=0;j<n;j++)
		{
			if(s[j]=='S')
			{
				rk[1]=i;rk[2]=j;
			}
			if(s[j]=='T')
			{
				ck[1]=i;ck[2]=j;
			}
			if(s[j]!='#')bz[i][j]=1;
		}
	}
	int x,y,t=1,w=1;
	que[1][1]=rk[1];que[1][2]=rk[2];que[1][3]=0;
	while(t<=w)
	{
		for(i=0;i<=3;i++)
		{
			x=que[t][1]+dx[i];
			y=que[t][2]+dy[i];
			if(bz[x][y]==1)
			{
				w++;
				que[w][1]=x;que[w][2]=y;
				que[w][3]=que[t][3]+1;
				bz[x][y]=0;
				if(x==ck[1]&&y==ck[2])
				{
					printf("%d",que[w][3]);
					return 0;
				}
			}
		}
		
		t++;
	}
	return 0;
}

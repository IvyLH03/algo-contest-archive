#include<cstdio>
using namespace std;
int bz[41][41],que[1601][4];
int dx[4]={1,-1,0,0},
	dy[4]={0,0,-1,1};
char s[41];
int main()
{
	int i,j,m,n;
	scanf("%d%d\n",&m,&n);
	for(i=0;i<m;i++)
	{
		gets(s);
		for(j=0;j<n;j++)
			if(s[j]=='.')bz[i][j]=1;
	}
	que[1][1]=0;que[1][2]=0;que[1][3]=1;
	int x,y,t=1,w=1;
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
				if(x==m-1&&y==n-1)
					printf("%d",que[w][3]);
				bz[x][y]=0;
			}
		}
		t++;
	}
	return 0;		
}

#include<cstdio>
using namespace std;
int bz[201][201],bs[3],nl[3],que[40001][4],sc[11];
char s[201];
int dx[4]={0,0,1,-1},
	dy[4]={1,-1,0,0};
int main()
{
	int t,i,j,m,n,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%d%d\n",&m,&n);
		for(i=0;i<m;i++)
		{    
			gets(s);
			for(j=0;j<n;j++)
			{
				if(s[j]=='S')
				{
					bs[1]=i;bs[2]=j;
				}
				if(s[j]=='E')
				{
					nl[1]=i;nl[2]=j;
				}
				if(s[j]!='#')bz[i][j]=1;
			}
			
		}
		int x,y,t=1,w=1;
		que[1][1]=bs[1];que[1][2]=bs[2];que[1][3]=0;
		while(t<=w)
		{
			for(i=0;i<=3;i++)
			{
				x=que[t][1]+dx[i];
				y=que[t][2]+dy[i];
				if(bz[x][y]==1)
				{
					w++;
					que[w][1]=x;
					que[w][2]=y;
					que[w][3]=que[t][3]+1;
					bz[x][y]=0;
					if(x==nl[1]&&y==nl[2]&&sc[k]==0)
					{//printf(".");
						sc[k]=que[w][3];
					}
				}
			}
			t++;
		}
	}
	for(i=1;i<=t;i++)
	{
		if(sc[i]==0)printf("oop!\n");
		else
		 printf("%d\n",sc[i]);
	}
	return 0;
}

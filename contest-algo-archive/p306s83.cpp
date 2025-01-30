#include<cstdio>
#include<cstring>
using namespace std;
int dx[12]={1,1,-1,-1,2,2,-2,-2,2,2,-2,-2},
	dy[12]={2,-2,2,-2,1,-1,1,-1,2,-2,2,-2};
int s[101][101],que[10000][4],x1,y1,x2,y2;
int main()
{
	memset(s,-1,sizeof(s));
	int head=1,tail=1;
	que[1][1]=1;que[1][2]=1;que[1][3]=0;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	while(head<=tail)
	{
		for(int d=0;d<=11;d++)
		{
			int x=que[head][1]+dx[d];
			int y=que[head][2]+dy[d];
			if(x>0&&y>0)
				if(s[x][y]==-1)
				{
					s[x][y]=que[head][3]+1;
					tail++;
					que[tail][1]=x;
					que[tail][2]=y;
					que[tail][3]=s[x][y];
					if(s[x1][y1]>0&&s[x2][y2]>0)
					{
						printf("%d\n%d",s[x1][y1],s[x2][y2]);
						return 0;
					}
				}
		}
	head++;
	}
 return 0;
}

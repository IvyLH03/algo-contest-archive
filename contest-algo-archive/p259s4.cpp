#include<cstdio>
#include<cstring>
using namespace std;
char s[101];
bool bz[101][101],rs[101];
int dx[4]={0,0,1,-1},
	dy[4]={1,-1,0,0};
int que[101][3];
int main()
{
	int x,y,i,n,m,j,k,ha,la,hb,lb,t=1,w=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d\n",&m);
		for(j=0;j<m;j++)
		{
			gets(s);
			for(k=0;k<m;k++)
			{
				if(s[k]=='#')bz[j][k]=1;	
			}
		}
		scanf("%d%d%d%d",&ha,&la,&hb,&lb);
		que[1][1]=ha;que[1][2]=la;
		t=1;w=1;
		while(t<=w)
		{
			for(j=0;j<=3;j++)
			{
				x=que[t][1]+dx[j];y=que[t][2]+dy[j];
				if((x>=0&&x<m)&&(y>=0&&y<m)&&(!bz[x][y]))
				{
					w++;
					que[w][1]=x;que[w][2]=y;
					bz[x][y]=1;
					if(x==hb&&y==lb)
					{
						rs[i]=1;
					}
				}
			}
			t++;
		}
		memset(bz,0,sizeof(bz));
	}
	for(i=1;i<=n;i++)
	{
		if(rs[i])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

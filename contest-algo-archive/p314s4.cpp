#include<cstdio>
#include<cstring>
using namespace std;
int bz[100][100],m,n,rn[3],xy[3],que[10000][4]; 
char s[100];
int dx[4]={0,0,1,-1},sc[100],
	dy[4]={1,-1,0,0};
void ksc(int nn)
{
	for(int i=1;i<nn;i++)
	{
		if(sc[i]==0)printf("-1");
		else printf("%d",sc[i]);
		if(i!=nn-1)printf("\n");
	}
}
int main()
{
	int nn,i,j;
	for(nn=1;;nn++)
	{
		scanf("%d%d",&m,&n);
		if(m==0)
		{
			ksc(nn);return 0;
		}
		else getchar();
		for(i=0;i<m;i++)
		{
			gets(s);
			for(j=0;j<n;j++)
			{
				if(s[j]=='@')
				{
					rn[1]=i;rn[2]=j;
				}
				if(s[j]=='*')
				{
					xy[1]=i;xy[2]=j;
				}
				if(s[j]!='#')
				{
					bz[i][j]=1;
				}
			}
		}
			//	printf(".");
		int x,y,t=1,w=1;
		que[1][1]=rn[1];que[1][2]=rn[2];que[1][3]=0;
		while(t<=w)
		{
			for(i=0;i<=3;i++)
			{
				x=que[t][1]+dx[i];
				y=que[t][2]+dy[i];
				if(bz[x][y]==1)
				{
					//printf("%d ",nn);
					w++;
					que[w][1]=x;que[w][2]=y;
					que[w][3]=que[t][3]+1;
					if(xy[1]==que[w][1]&&xy[2]==que[w][2])
						sc[nn]=que[w][3];
					bz[x][y]=0;
				}
			}
			t++;
		}
	}

	return 0;
}

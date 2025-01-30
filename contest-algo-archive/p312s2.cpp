#include<cstdio>
using namespace std;
int que[10000][3],td[101][101],num=0,m,n;
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};
char s[101];
void doit(int p,int q)
{
	num++;
	int x,y,i,t=1,w=1;
	td[p][q]=0;
	que[1][1]=p;que[1][2]=q;
	while(t<=w)
	{
		for(i=0;i<=7;i++)
		{
			x=que[t][1]+dx[i];
			y=que[t][2]+dy[i];
			if(td[x][y])
			{
				w++;
				que[w][1]=x;que[w][2]=y;
				td[x][y]=0;			
			}
		}
		t++;
	}
	
}
int main()
{
	int i,j;
	scanf("%d%d",&m,&n);
	getchar();
	for(i=1;i<=m;i++)
	{
		gets(s);
		for(j=1;j<=n;j++)
			if(s[j-1]=='W')td[i][j]=1;
	}
	
//	for(int k=1;k<=n;k++)
//	{
//		for(int g=1;g<=m;g++)
//			printf("%d",td[g][k]);
//		printf("\n");
//	}
//	printf("-------\n");
	
//						int r=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(td[i][j]==1)
			{	doit(i,j);			//printf("x:%d y:%d\n",j,i);
						//	r++;
						//	printf("%d:\n",r);						
						//	for(int k=1;k<=n;k++)
						//	{
						//		for(int g=1;g<=m;g++)
						//			printf("%d",td[g][k]);
						//		printf("\n");
						//	}
						//	printf("\n");
				
			}
	printf("%d\n",num);
				
				
	return 0;
	
}

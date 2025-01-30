#include<cstdio>
using namespace std;
int dx[4]={-1,0,1,0},
	dy[4]={0,1,0,-1};
int bz[100][100],num=0,n,m;
void doit(int p,int q)
{
	int x,y,t,w,i;
	int h[1000][2];
	num++;bz[p][q]=0;
	t=0;w=1;h[1][1]=p;h[1][2]=q;
	do
	{
		t++;
		for(i=0;i<=3;i++)
		{
			x=h[t][1]+dx[i];y=h[t][2]+dy[i];
			if((x>=0)&&(x<m)&&(y>=0)&&(y<n)&&(bz[x][y]))
			{
				w++;
				h[w][1]=x;
				h[w][2]=y;
				bz[x][y]=0;
			}
		}
	}while(t<w);
}
int main()
{
	int i,j;
	char s[100],ch;
	scanf("%d%d\n",&m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			bz[i][j]=1;
	for(i=0;i<m;i++)
	{
		gets(s);
		for(j=0;j<n;j++)
			if(s[j]=='0')bz[i][j]=0;
	}
	for(i=0;i<=m-1;i++)
		for(j=0;j<=n-1;j++)
			if(bz[i][j])doit(i,j);
	printf("NUMBER of cells=%d",num);
	return 0;
}



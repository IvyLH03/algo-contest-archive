#include<cstdio>
#include<cstring>
using namespace std;
char s[6]={'i','z','h','o','n','g'},dt[101][101];
int n;
int dx[8]={0,1,1,1,-1,-1,-1,0},
	dy[8]={1,0,1,-1,1,-1,0,-1};
bool pdy[101][101],bz[101][101];
void print()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(bz[i][j]==1)
				printf("%c",dt[i][j]);
			else printf("*");
		}
		printf("\n");
	}
}
void bj(int ax,int ay,int ch,int i)
{				//printf("7.");
	
	if(ch==7)return;
	bz[ax][ay]=1;
	bj(ax+dx[i],ay+dy[i],ch+1,i);
}
void search(int ax,int ay,int ch,int i)
{
	if(ax>n||ay>n||ay<0||ax<0)return;
	if(ch>=6)
	{
		bj(ax,ay,0,7-i);
		return;
	}
	int x=ax+dx[i],y=ay+dy[i];
	if(dt[x][y]!=s[ch]) return;
	else search(x,y,ch+1,i);
	
}
void search0()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(dt[i][j]=='y')
			{
				for(k=0;k<=7;k++)
					search(i,j,0,k);
			}
		}
	}
}
int main()
{
	int i,j;
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
	{
		gets(dt[i]);
	}
	search0();
	print();
	return 0;
}

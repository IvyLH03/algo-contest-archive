#include<cstdio>
#include<cstring>
using namespace std;
char s[21];
int m,n,rs[101],t;
bool bz[21][21];
int search(int x,int y)
{
	if(x>0&&x<=m&&y>0&&y<=n&&(!bz[x][y]))
	{
		bz[x][y]=1;
		return 1+search(x-1,y)+search(x+1,y)+search(x,y-1)+search(x,y+1);
		
	}
	else return 0;
}
int main()
{
	scanf("%d%d\n",&n,&m);
	int i,j,ax,ay;
	while(m!=0)
	{
		t++;
		memset(bz,0,sizeof(bz));
		for(i=1;i<=m;i++)
		{
			gets(s);
			for(j=1;j<=n;j++)
			{
				if(s[j]=='@')
				{
					ax=i;ay=j;
				}
				if(s[j]=='#')
					bz[i][j]=1;				
			}
		}
		rs[t]=search(ax,ay);
		scanf("%d%d\n",&n,&m);
	}
	for(i=1;i<=t;i++)
	{
		printf("%d\n",rs[i]);
	}
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;
int n,m,ax[100001],ay[100001],tot[1000001],lt[1001][1001],tlt;
char sr[1001];
bool dt[1001][1001],bz[1001][1001];
void search(int x,int y,int w)
{
	bool q=dt[x][y]; 
	if((x<=0)||(y<=0)||(x>n)||(y>n)||(q!=w)||(bz[x][y]==1))
	{
		return;
	}
	bz[x][y]=1;
	lt[x][y]=tlt;
	tot[tlt]++;
	if(w==1)
		w=0;
	else
		w=1;
	search(x,y+1,w);
	search(x+1,y,w);
	search(x,y-1,w);
	search(x-1,y,w);
}
int main()
{
	scanf("%d%d\n",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	{
		gets(sr);
		for(j=0;j<n;j++)
			if(sr[j]=='1')
				dt[i][j+1]=1;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(!bz[i][j])
			{
				tlt++;
				search(i,j,dt[i][j]);
			}
	for(i=1;i<=m;i++)
		scanf("%d%d",&ax[i],&ay[i]);
	for(i=1;i<=m;i++)
		printf("%d\n",tot[lt[ax[i]][ay[i]]]);
	return 0;
}

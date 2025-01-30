#include<cstdio>	//ª·TLE. 
#include<cstring>
using namespace std;
int n,m,ax,ay,tot[100001];
char sr[1001];
bool dt[1001][1001],bz[1001][1001];
void search(int x,int y,bool w,int m)
{
	bool q=dt[x][y]; 
	if((x<=0)||(y<=0)||(x>n)||(y>n)||(q!=w)||(bz[x][y]==1))
	{			//	printf("7.");
		return;
	}
	bz[x][y]=1;tot[m]++;		
	if(w==0)
		w=1;
	else 
		w=0;
			//	printf("(%d,%d)\n",x,y);
	search(x+1,y,w,m);
	search(x,y+1,w,m); 
	search(x-1,y,w,m);
	search(x,y-1,w,m);
	
}
int main()
{
	scanf("%d%d\n",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	{
		gets(sr);
		for(j=0;j<n;j++)
			if(sr[j]=='1')dt[i][j+1]=1;
	} 
	for(i=1;i<=m;i++)
	{		
		scanf("%d%d",&ax,&ay);
		if(dt[ax][ay]==0)search(ax,ay,0,i);
		else search(ax,ay,1,i);
		memset(bz,0,sizeof(bz));
	}
	for(i=1;i<=m;i++)
		printf("%d\n",tot[i]);
	return 0;
}

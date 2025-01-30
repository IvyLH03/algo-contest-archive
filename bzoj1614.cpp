#include<cstdio>
#include<algorithm>
using namespace std;
int n,p,k,l[1001][1001],ans,s[10001];
bool c[1001][1001]={},flag_main=0,bz[1001];
void dfs(int x,int y)		
{								
	if(x==n)
	{
		int i,cst=0;
		flag_main=1;
		sort(s+1,s+y);
		for(i=1;i<=y-k;i++)
			cst+=s[i];
		if(cst<ans) ans=cst;
		return;
	}
	int i;
	for(i=1;i<=n;i++)
	{
		if(c[x][i])
		{	
			if(!bz[i])
			{
				bz[i]=1;s[y]=l[x][i];
				dfs(i,y+1);
				bz[i]=0;s[y]=0;
			}
		} 		 
	}
} 
int main()
{
	ans=10000001;
	scanf("%d%d%d",&n,&p,&k);
	int x,y,i;
	for(i=1;i<=p;i++)
	{
		scanf("%d%d",&x,&y);
		scanf("%d",&l[x][y]);
		c[x][y]=c[y][x]=1;
		l[y][x]=l[x][y];
	}

	dfs(1,1);
					
	if(!flag_main)	printf("-1");
	else printf("%d",ans);
	return 0;
}

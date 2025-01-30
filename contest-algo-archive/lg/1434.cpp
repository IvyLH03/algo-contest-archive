#include<cstdio>
using namespace std;
int m,n,a[101][101],ans,f[101][101];
bool  bz[101][101];
int max(int a,int b)
{
	return a>b? a:b;
}
int dfs(int x,int y)
{
	int s=0;
	bz[x][y]=0;
	
	if(f[x][y]!=1)
		return f[x][y]; 
	
	if(a[x+1][y]<a[x][y]&&bz[x+1][y]) s=max(s,dfs(x+1,y)+1);
	if(a[x-1][y]<a[x][y]&&bz[x-1][y]) s=max(s,dfs(x-1,y)+1);
	if(a[x][y+1]<a[x][y]&&bz[x][y+1]) s=max(s,dfs(x,y+1)+1);
	if(a[x][y-1]<a[x][y]&&bz[x][y-1]) s=max(s,dfs(x,y-1)+1);
	
	bz[x][y]=1;
	f[x][y]=max(f[x][y],s);
	return f[x][y];
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			f[i][j]=1;bz[i][j]=1;
		}
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			ans=max(ans,dfs(i,j));
			
	printf("%d\n",ans);
	return 0;
					
}

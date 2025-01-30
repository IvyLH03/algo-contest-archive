#include<cstdio>
using namespace std;
const int maxn=1005;
int a[maxn][maxn],f[maxn],n,ans;
void dfs(int x,int y,int curr)
{
	if(x==n)
	{
		if(curr>ans)ans=curr;
		return;
	}
	dfs(x+1,y,curr+a[x+1][y]);
	dfs(x+1,y+1,curr+a[x+1][y+1]);
	
} 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	ans=0;
	dfs(1,1,a[1][1]);
	printf("%d",ans);
	return 0;
	
}

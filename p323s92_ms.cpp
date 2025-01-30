#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=505;
int a[maxn][maxn],f[maxn][maxn],n;

int dfs(int x,int y)
{
	if(f[x][y]==-1)
	{
		if(x==n)
			f[x][y]=a[x][y];
		else f[x][y]=a[x][y]+max(dfs(x+1,y),dfs(x+1,y+1)); 
	}
	return f[x][y];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			{
				scanf("%d",&a[i][j]);
				f[i][j]=-1;
			}
	dfs(1,1);
	printf("%d",f[1][1]);
	return 0;
}

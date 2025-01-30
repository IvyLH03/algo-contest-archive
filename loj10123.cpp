#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,f[3][50007][27];
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&f[1][i][0]);
		f[2][i][0]=f[1][i][0];
	}
	for(j=1;j<=27;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			f[1][i][j]=max(f[1][i][j-1],f[1][i+(1<<j-1)][j-1]);
			f[2][i][j]=min(f[2][i][j-1],f[2][i+(1<<j-1)][j-1]);
		}
	}
	int x,y,s,ans;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		s=log2(y-x+1);
		ans=max(f[1][x][s],f[1][y-(1<<s)+1][s])-min(f[2][x][s],f[2][y-(1<<s)+1][s]);
		printf("%d\n",ans);
	}
	return 0;
}

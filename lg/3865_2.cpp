#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100007;
int f[N][400];
int m,n;
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&f[i][0]);
	}
	for(j=1;j<=21;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	int x,y,s;
	int ans;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		s=log2(y-x+1);			
		ans=max(f[x][s],f[y-(1<<s)+1][s]);
		printf("%d\n",ans);
	}
	return 0;
} 

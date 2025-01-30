#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100007;
long long t[2*N][40],n,m;//a[2*N];
int main()
{
	scanf("%lld%lld",&n,&m);
	long long i,j;
	for(i=1;i<=n;i++)
		scanf("%lld",&t[i][0]);
	for(i=1;i<=log2(n);i++)
	{
		for(j=1;j+(1<<i)-1<=n;j++)
		{
			t[j][i]=min(t[j][i-1],t[j+(1<<i-1)][i-1]);
		}
	}
	long long x,y,k,ans;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		k=log2(y-x);
		ans=min(t[x][k],t[y-(1<<k)+1][k]);
		printf("%lld ",ans);
	}
	return 0;
	
}

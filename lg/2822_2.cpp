#include<cstdio>
#include<algorithm>
using namespace std;
const int N=4007,M=100007;
int n[M],m[M],k,t;
unsigned long long jc[N],c[N][N],sum[N][N];
int main()
{
	//freopen("P2822_2.in","r",stdin);
	scanf("%d%d",&t,&k);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n[i],&m[i]);
		n[0]=max(n[0],n[i]);
		m[0]=max(m[0],m[i]);
	}
	c[1][1]=1;
	for(int i=0;i<=n[0];i++) c[i][0]=1;
	for(int i=1;i<=n[0];i++)
	{
		for(int j=1;j<=i&&j<=m[0];j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
			//printf("%d ",c[i][j]);
		}
		//printf("\n");
	}
	for(int i=1;i<=n[0];i++)
	{
		for(int j=1;j<=i,j<=m[0];j++)
		{
			if(i>j) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			else sum[i][j]=sum[i][j-1];
			if(c[i][j]%k==0&&j<=i&&j<=m[0]) sum[i][j]++;
			//printf("%d ",sum[i][j]);
		}
		//printf("\n");
	}
	for(int i=1;i<=t;i++)
		printf("%llu\n",sum[n[i]][m[i]]);
	return 0;
		
}

#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100007;
long long a[N],f[N][27];
int MaxLog,log[N],m,n;
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	log[0]=-1;
	for(i=1;i<=n;i++)
	{
		log[i]=log[i>>1]+1;f[i][0]=a[i];
	}
	MaxLog=log[n];
	for(j=1;j<=MaxLog;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	int x,y,s;
	long long ans;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		s=log[y-x+1];			
		ans=max(f[x][s],f[y-(1<<s)+1][s]);
		printf("%lld\n",ans);
	}
	return 0;
} 

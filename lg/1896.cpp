#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10;
long long n,K,f[N][200][200],c[200],num[200],tot,ans;
int main()
{
	scanf("%lld%lld",&n,&K);
	long long i,j,k,t;
	for(i=0;i<(1<<n);i++)
	{
		if(i&i<<1) continue;
		c[++tot]=i;				//	printf("*");
		for(j=0;j<n;j++)
		{					//	printf("*");
			if(i&(1<<j)) 
			{					//	printf("*");
				num[tot]++;
			}
		}
	}
	
						//		for(i=1;i<=tot;i++)
						//			printf("%d ",num[i]);
						//		printf("\n");
	f[0][1][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=tot;j++)
			for(k=0;k<=K;k++)
				if(k>=num[j])
					for(t=1;t<=tot;t++)
						if(!(c[j]&c[t])&&!(c[j]&(c[t]<<1))&&!(c[j]&(c[t]>>1)))
							f[i][j][k]+=f[i-1][t][k-num[j]];
	}
	for(i=1;i<=tot;i++)
		ans+=f[n][i][K];
	printf("%lld",ans);
	return 0;
}

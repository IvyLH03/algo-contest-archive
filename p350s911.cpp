#include<cstdio>
using namespace std;
const int maxm=201,maxn=31;
int m,n;
int w[maxn],c[maxn];
int f[maxn][maxn];
int max(int x,int y)
{
	if(x<y)return y;
	else return x;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&c[i]);
	for(int i=1;i<=n;i++)
		for(int v=m;v>0;v--)
			if(w[i]<=v)
				f[i][v]=max(f[i-1][v],f[i-1][v-w[i]]+c[i]);
			else
				f[i][v]=f[i-1][v];
	printf("%d",f[n][m]);
	return 0;
}

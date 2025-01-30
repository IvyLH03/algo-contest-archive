#include<cstdio>
using namespace std;
const int N=37;
int f[N][N],rt[N][N],ls[N],rs[N],n,a[N];
void print(int l,int r)
{
	if(r<l) return;
	if(l==r)
	{
		printf("%d ",l);return;
	}
	printf("%d ",rt[l][r]);
	print(l,rt[l][r]-1);
	print(rt[l][r]+1,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) f[i][i-1]=1,f[i][i]=a[i],rt[i][i]=i;
	for(int len=1;len<=n-1;len++)
	{
		for(int i=1;i<=n-len;i++)
		{
			int j=i+len;
			for(int k=i;k<=j;k++)
			{
				if(f[i][j]<f[i][k-1]*f[k+1][j]+a[k])
				{
					rt[i][j]=k;
					ls[k]=rt[i][k-1];rs[k]=rt[k+1][j];
					f[i][j]=f[i][k-1]*f[k+1][j]+a[k];
				}
			}
		}
	}
	printf("%d\n",f[1][n]);
	print(1,n);
	return 0;
}

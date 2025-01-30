#include<cstdio>
using namespace std;
int n,sum,yh[13][13],ans[13];
bool flag,pd[13];
void print(int a[])
{
	printf("%d",a[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",a[i]);
}
void dfs(int s,int t)// sum, current step; 
{
	if(flag)
		return;
	if(s>sum)
		return;		
	if(t>n)
	{
		if(s==sum&&(!flag))
		{
			print(ans);flag=1;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(pd[i]==0)
		{
			pd[i]=1;
			ans[t]=i;
			dfs(s+yh[n][t]*i,t+1);
			pd[i]=0;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&sum);
	int i,j;
	yh[1][1]=1;
	for(i=2;i<=n;i++)
	{
		for(j=(i+1)/2;j<=n;j++)
			yh[i][j]=yh[i][i+1-j]=yh[i-1][j]+yh[i-1][j-1];
	}
	dfs(0,1);
	return 0;
} 

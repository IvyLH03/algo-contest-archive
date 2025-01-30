#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,c,d[57],p[57],w,t,ans;
bool vis[57];
void dfs(int x,int s)
{
	int i;
	if(w>=ans)
		return;
	if(s==n)
	{
		ans=min(ans,w);return;
	}
	bool flag=0;
	for(i=x-1;i>=1;i--)
	{
		if((!vis[i])&&(!flag))
		{
			flag=1;
			vis[i]=1;t+=d[x]-d[i];w+=t*p[i];
			dfs(i,s+1);
			vis[i]=0;w-=t*p[i];t-=d[x]-d[i];
		}
	}
	flag=0;
	for(i=x+1;i<=n;i++)
	{
		if((!vis[i])&&(!flag))
		{
			flag=1;
			vis[i]=1;t+=d[i]-d[x];w+=t*p[i];
			dfs(i,s+1);
			vis[i]=0;w-=t*p[i];t-=d[i]-d[x];
		}
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&c);
	ans=10000007;		//¿ÉÄÜ²»¹»£¿ 
	for(i=1;i<=n;i++)
		scanf("%d%d",&d[i],&p[i]);
	vis[c]=1;
	dfs(c,1);
	printf("%d",ans);
	return 0;
}
 

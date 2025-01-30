#include<cstdio>
using namespace std;
int n,k,ans;
void dfs(int l,int s,int t)
{
	if(t==k)
	{
		if(s==n) ans++;
		return;
	}
	for(int i=l;s+i*(k-t)<=n;i++)
		dfs(i,s+i,t+1);
}
int main()
{
	scanf("%d%d",&n,&k);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}

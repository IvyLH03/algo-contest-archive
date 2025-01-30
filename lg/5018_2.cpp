#include<cstdio>
#include<algorithm>
using namespace std;
int n,ls[100007],rs[100007],num[100007],ans,f[100007];
bool dc[100007];
void dfs(int x)
{
	if(ls[x]==-1&&rs[x]==-1)
	{
		f[x]=1;return;
	}
	if(ls[x]!=-1)
		dfs(ls[x]);
	if(rs[x]!=-1)
		dfs(rs[x]);
	f[x]=f[ls[x]]+f[rs[x]]+1;
	
}
bool pd(int x,int y)			//似乎可以优化 
{
	if(x==-1&&y==-1)
		return 1;
	if(x!=-1&&y!=-1&&pd(ls[x],rs[y])&&pd(rs[x],ls[y]))
		return 1;
	return 0;
}
int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(i=1;i<=n;i++)
		scanf("%d%d",&ls[i],&rs[i]);
	dfs(1);
	for(i=1;i<=n;i++)
	{
		if(pd(ls[i],rs[i]))
			ans=max(ans,f[i]);
	}
	printf("%d",ans);
	return 0;
}

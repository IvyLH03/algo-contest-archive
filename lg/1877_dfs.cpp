#include<cstdio>
#include<algorithm>
using namespace std;
int n,bl,ml,c[51],ans;
bool flag;
void dfs(int x,int l)
{
	if(l>ml||l<0)
		return;
	if(x>n)
	{
		flag=1;
		ans=max(ans,l);
		return;
	}
	dfs(x+1,l-c[x]);
	dfs(x+1,l+c[x]);
}
int main()
{
	int i;
	scanf("%d%d%d",&n,&bl,&ml);
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	
	dfs(1,bl);
	if(!flag)
	{
		printf("-1");return 0;
	}
	printf("%d",ans);
	return 0;
}

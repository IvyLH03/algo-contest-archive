#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std; 
int n,t,v[101],c[101],ans;
bool flag;
void chg(int sum,int tot,int x,int y)
{
	int i;
	if(!sum)
	{
		flag=1;ans=min(ans,tot);
		return;
	}
	if(sum<0)
		return;
	if(y==c[x])
		chg(sum,tot,x+1,0);
	for(i=1;i<=n;i++)
		chg(sum-v[i],tot+1,x,y+1);
}
void dfs(int tot,int x,int sum,int y)
{
	int i;
	if(x>n)
		return;
	if(sum>t)
		chg(sum,tot,1,0);
	if(y==c[x])
		dfs(tot,x+1,sum,0);
	for(i=1;i<=c[x];i++)
		dfs(tot+1,x,sum+v[x],y+1);
	
}
int main()
{
	ans=10000001;
	int i,j,k;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dfs(0,1,0,0);
	if(!flag) printf("-1");
	else printf("%d",ans);
	return 0;
}

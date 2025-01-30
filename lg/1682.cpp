#include<cstdio>
#include<algorithm>
using namespace std;
const int N=250;
int fa[N],num[N],n,m,k,f;
bool vis[N][N];
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
 } 
void unionn(int x,int y)
{
	num[find(y)]=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[find(x)][i]||vis[find(y)][i]) num[find(y)]++,vis[find(y)][i]=1;
		vis[find(x)][i]=0;
	}
	fa[find(x)]=find(y);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&f);
	for(int i=1;i<=n;i++) fa[i]=i;
	int x,y,ans=1000000007;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		vis[x][y]=1;
	}
	for(int i=1;i<=f;i++)
	{
		scanf("%d%d",&x,&y);
		unionn(x,y);
	}
	for(int i=1;i<=n;i++)
		if(num[i]) ans=min(ans,num[i]);
	ans=min(n,ans+k);
	printf("%d",ans);
	return 0;
}

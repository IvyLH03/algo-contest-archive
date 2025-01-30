#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200007;
int n,to[N],que[N],ind[N],head,tail,ans;
bool vis[N];
int dfs(int x,int anc,int cnt)
{
	vis[x]=1;
	if(x==anc) return cnt;
	dfs(to[x],anc,cnt+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&to[i]);
		ind[to[i]]++;
	}
	for(int i=1;i<=n;i++) if(!ind[i]) que[++tail]=i;
	head=1;
	while(head<=tail)
	{
		ind[to[que[head]]]--;
		if(!ind[to[que[head]]]) que[++tail]=to[que[head]];
		head++;
	}
	ans=40000000;
	for(int i=1;i<=n;i++)
		if(ind[i]&&vis[i]==0) ans=min(ans,dfs(to[i],i,1)); 
	printf("%d\n",ans);
}

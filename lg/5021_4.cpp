#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=50007;
int n,m,head[N],etot,res,dp[N],nums[N],que[N];
bool vis[N];
struct edge{
	int next,to,v;
}e[N<<1];
void adde(int x,int y,int v)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	e[etot].v=v;
	head[x]=etot;
}
void dfs(int x,int f,int u)
{
	if(res>=m) return;
	int l=1,r=0;
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs(e[i].to,x,u);
	}
	memset(vis,0,sizeof(vis));
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to==f) continue;
		else que[++r]=dp[e[i].to]+e[i].v;
	sort(que+1,que+1+r);
	while(que[r]>=u) r--,res++;
	for(int i=1;i<=r;i++)
	{
		if(vis[i]) continue;
		int lbound=i+1,rbound=r,j=r+1;
		while(lbound<=rbound)
		{	//printf("*");
			int mid=lbound+(rbound-lbound>>1);
			if(que[mid]+que[i]>=u) j=mid,rbound=mid-1;
			else lbound=mid+1;	//¸Ð¾õ²»ÐÐ 
		}
		while(vis[j]) j++;
		if(j<=r) res++,vis[i]=vis[j]=1;
	}
	for(int i=r;i>=1;i--)
		if(!vis[i])
		{
			dp[x]=que[i];break;
		}
	
}
bool check(int x)
{
	memset(dp,0,sizeof(dp));
	res=0;dfs(1,0,x);
	if(res>=m) return 1;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	int x,y,v,l,r=0,mid,ans;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		adde(x,y,v);adde(y,x,v);r+=v;
	}
	while(l<=r)
	{
		mid=l+(r-l>>1);
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	 } 
	 printf("%d\n",ans);
	 return 0;
}

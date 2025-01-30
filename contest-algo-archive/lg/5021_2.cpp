#include<cstdio>
#include<algorithm>		
using namespace std;	//只考虑m=1的情况 
int n,m,ans;
struct node{
	int num,f,s[50007],df;
}a[5000];
bool vis[5007];
void dfs(int x,int d)
{
	if(vis[x])
		return;
	if(!a[x].num)
	{
		ans=max(ans,d);return;
	}
	vis[x]=1;
	dfs(a[x].f,d+a[x].df);
	for(int i=1;i<=a[x].num;i++)
		dfs(a[x].s[i],d+a[a[x].s[i]].df);
	vis[x]=0;
	
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j,k,x,y,z;

	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x].s[++a[x].num]=y;
		a[y].f=x;
		a[y].df=z;
	}
	
	for(i=1;i<=n;i++)
	{
		if(!a[i].num)
			dfs(a[i].f,a[i].df);
	}
	printf("%d",ans);
	return 0;
}

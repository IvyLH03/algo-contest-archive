#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,ans;
bool vis[57];
int d[57],p[57];
void dfs(int x,int t,int s,int w)	//在位置x，过了t秒(已经走了t米)，正在关第s盏灯,耗电w 
{
	int i;
	if(s==n)
	{		//printf(".");
		ans=min(ans,w);return;
	}
	
	vis[x]=1;
	for(i=1;i<=n;i++)
		if(!vis[i])
			dfs(d[i],abs(d[i]-x)+t,s+1,w+(abs(d[i]-x)+t)*p[i]);

	vis[x]=0;
}
int main()
{
	int i,c;
	ans=100000001;
	scanf("%d%d",&n,&c);
	for(i=1;i<=n;i++)
		scanf("%d%d",&d[i],&p[i]);
	dfs(d[c],0,1,0);
	printf("%d",ans);
	return 0;
}

#include<cstdio>
using namespace std;
const int N=160007;
int n,a[N],head[N],t[N],tot,ans,etot;
int max(int x,int y)
{
	return x>y?x:y;
}
struct edge
{
	int nxt,to;
}e[N>>1];
void adde(int x,int y)
{
	e[++etot].nxt=head[x];
	e[etot].to=y;
	head[x]=etot;
}
void dfs(int x,int f)
{
	t[x]=a[x];
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==f) continue;
		dfs(e[i].to,x);
		t[x]=max(t[x],t[x]+t[e[i].to]);
	}
	ans=max(ans,t[x]);
}
int main()
{
	scanf("%d",&n);int x,y;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		tot+=a[i];
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	}
	ans=tot;
	dfs(1,0);
	printf("%d",ans);
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
int d,g,ans;
bool flag;
struct node{
	int t,f,h;
}a[107];
bool comp(node x,node y)
{
	return x.t<y.t;
}
void dfs(int x,int hlt,int hei)
{
	if(a[x].t>hlt)
		return;
	if(a[x].t>=ans)
		return;
	if(hei>=d)
	{
		flag=1;ans=min(ans,a[x].t);return;
	}
	if(x==g) return;
	dfs(x+1,hlt+a[x+1].f,hei);
	dfs(x+1,hlt,hei+a[x+1].h);
}
int main()
{
	int i;
	scanf("%d%d",&d,&g);
	for(i=1;i<=g;i++)
		scanf("%d%d%d",&a[i].t,&a[i].f,&a[i].h);
	ans=100000007;
	sort(a+1,a+1+g,comp);
	dfs(0,10,0);
	if(!flag)
	{
		ans=10;
		for(i=1;i<=g;i++)
		{
			if(a[i].t>ans) break;
			ans+=a[i].f;
		}
	}
	printf("%d",ans);
	return 0;
		
}

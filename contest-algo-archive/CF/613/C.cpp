#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
ll x,que[1000007],ans,xtmp;
ll rd()
{
	ll x=0;char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';c=getchar();
	}
	return x;
}
void dfs(int cnt,ll num1,ll num2)
{
//	printf("%d %d %d\n",cnt,num1,num2);
	if(cnt>que[0])
	{
		if(max(num1,num2)<ans) ans=max(num1,num2);
		return;
	}
	dfs(cnt+1,num1*que[cnt],num2);
	dfs(cnt+1,num1,num2*que[cnt]);
//	printf("*");
}
int main()
{
	xtmp=rd();x=xtmp;ans=x;
	if(x==1)
	{
		printf("1 1");return 0;
	}
	for(int i=2;i<=sqrt(x)&&x>1;i++)
	{
		if(x%i) continue;
		que[++que[0]]=i;x/=i;
		while(x%i==0) que[que[0]]*=i,x/=i;
	}
	if(x>1) que[++que[0]]=x;//printf("que[0]=%d\n",que[0]);
//	for(int i=1;i<=que[0];i++) printf("%d ",que[i]); printf("\n");
	if(que[0]==1)
	{
		printf("1 %lld",que[1]);
		return 0;
	}
	
	else dfs(1,1,1);
	xtmp/=ans;
	printf("%lld %lld",ans,xtmp);
	return 0;
}

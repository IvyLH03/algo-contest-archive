#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e7+7;
bool istprime[N];
int prime[N],que[N],fr,fr2,a,b,tmp;
struct node{
	int x,y;
}ans[N];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
ll rd()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';c=getchar();
	}
	return x*f;
}
void sprime()
{
	prime[0]=0;istprime[1]=istprime[0]=1;
	for(int i=2;i<=N-7;i++)
	{	
		if(!istprime[i]) prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&i*prime[j]<=N-7;j++)
        {
            istprime[i*prime[j]]=1;
            if(!(i%prime[j]))
                break;
        }
	}
}
void dfs(int p,int x,int y)
{
	if(p>fr)
	{
		if(x!=a&&y!=a&&x<y)ans[++fr2].x=x,ans[fr2].y=y;
		return;
	}
	dfs(p+1,x*prime[p],y);
	dfs(p+1,x,y*prime[p]);
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	ll t=rd();sprime();
	while(t--)
	{
		a=rd(),b=rd();
		if(b%a)
		{
			printf("0\n");continue;
		}
		tmp=b,b/=a,fr=fr2=0;
		for(int i=1;i<=prime[0]&&b;i++)
		{
			if(!(b%prime[i])) que[++fr]=prime[i],b/=prime[i];
			else continue;
			while(b%prime[i]==0&&b) que[fr]+=prime[i],b/=prime[i];
		}
		dfs(1,a,a);
		sort(ans+1,ans+1+fr2,cmp);
		printf("%d\n",fr2+1);
		printf("%d %d\n",a,tmp);
		for(int i=1;i<=fr2;i++)
			printf("%d %d\n",ans[i].x,ans[i].y);
	}
	return 0;
}

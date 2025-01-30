#include<cstdio>
#define ll long long
using namespace std;
const int N=1e8+7;
bool istprime[N];
int prime[N],n;
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
	int t=0;istprime[1]=istprime[0]=1;
	for(int i=2;i<=n;i++)
	{	
		if(!istprime[i]) prime[++t]=i;
		for(int j=1;j<=t&&i*prime[j]<=n;j++)
        {
            istprime[i*prime[j]]=1;
            if(!(i%prime[j]))
                break;
        }
	}
}
int main()
{
	n=rd();int t=rd(),a;
	sprime();
	while(t--)
	{
		a=rd();
		if(istprime[a]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}

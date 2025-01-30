#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100007;
ll rd()
{
	ll x=0,f=1;char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';c=getchar();
	}
	return x*f;
}
int t,n,a[N];ll sum,tmp,minn,maxn,ans;
int main()
{
	t=rd();
	while(t--)
	{
		n=rd();sum=tmp=maxn=minn=ans=0;bool flag=0;
		for(int i=1;i<n;i++)
		{
			a[i]=rd();sum+=a[i];
			ans=max(sum-minn,ans);
			if(sum<=minn)
			{
				flag=1;minn=tmp;
			} 
		}
		a[n]=rd();sum+=a[n];
		if(sum-minn>ans&&flag) ans=sum-minn;
		if(ans>=sum) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

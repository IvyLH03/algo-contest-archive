#include<cstdio>
using namespace std;
const int N=5*1e5;
int t[N],n,m,a;
int lowbit(int x)
{
	return x&(-x);
}
void change(int x,int v)
{
	while(x<=n)
	{
		t[x]+=v;
		x+=lowbit(x);
	}
}
int sum(int x)
{
	int s=0;
	while(x)
	{
		s+=t[x];
		x-=lowbit(x);
	}
	return s;
}
int main()
{
	int i,j,k,x,y,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		change(i,a);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)
		{
			change(x,y);
		}
		if(k==2)
		{
			ans=sum(y)-sum(x-1);
			printf("%d\n",ans);
		}
	}
	return 0;
}

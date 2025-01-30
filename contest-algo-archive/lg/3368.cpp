#include<cstdio>
using namespace std;
const int N=500007;
int a[N],t[N],n,m;
int lowbit(int x)
{
	return x&(-x);
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
void change(int x,int v)
{
	while(x<=n)
	{
		t[x]+=v;
		x+=lowbit(x);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j,k,x,y,v;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		change(i,a[i]-a[i-1]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d%d",&x,&y,&v);
				change(x,v);
				change(y+1,-v);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",sum(x));
		}
	}
	return 0;
}

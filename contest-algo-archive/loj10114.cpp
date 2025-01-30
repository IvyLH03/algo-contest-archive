#include<cstdio>
using namespace std;
const int N=15007,X=320007;
int x[N],t[X],n,y,a[N];
int lowbit(int k)
{
	return k&(-k);
}
void change(int k)
{
	while(k<=X)
	{
		t[k]++;
		k+=lowbit(k);
	}
}
void sum(int k)
{
	int ans=0;
	while(k)
	{
		ans+=t[k];
		k-=lowbit(k);
	}
	a[ans]++;
}
int main()
{
	scanf("%d",&n);
	int i,j,k,ans;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y);
		sum(x[i]+1);
		change(x[i]+1);
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}

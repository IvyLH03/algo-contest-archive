#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500007;
int last[2*N],n,m,t[2*N],b[2*N],ans[2*N];
struct node{
	int l,r,num;
}a[N];
bool comp(node x,node y)
{
	return x.r<y.r;
}
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
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].num=i;
	}
	sort(a+1,a+1+m,comp);
	int z=1;
	for(i=1;i<=m;i++)
	{					//	printf("*");
		for(j=z;j<=a[i].r;j++)
		{
			if(last[b[j]]) change(last[b[j]],-1);
			change(j,1);last[b[j]]=j;
		}
		z=a[i].r+1;
		ans[a[i].num]=sum(a[i].r)-sum(a[i].l-1);
	}
	for(i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}

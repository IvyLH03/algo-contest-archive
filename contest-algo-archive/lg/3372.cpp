#include<cstdio>	//¸ÉÀ¬»ø 
#include<algorithm>
using namespace std;
const int N=100000;
int n,m,x,y;
long long a[N],t[2*N],z;
void mt(long long x,long long l,long long r);
{
	if(l=r)
	{
		t[x]=a[l];return;
	}
	int mid=l+(r-l)/2;
	mt(x<<1,l,mid);
	mt(x<<1+1,mid+1,l);
	t[x]=t[x<<1]+t[x<<1+1];
}
void change(int k,int l,int r)
{
	if(l>y||r<x) return;
	if(l==r)
	{
		t[k]+=z;return;
	}
	int mid=l+(r-l)/2;
	change(l,mid);
	change(mid+1,r);
	t[k]=t[k<<1]+t[k<<1+1];
}
void plus(int k,int l,int r)
{
	
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j,k;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	mt(1,1,n);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d%d",&x,&y,&z);
			change(1,1,n);
		}
		else
		{
			scanf("%d%d",&x,&y);
			plus(1,1,n);
		}
	}
	return 0;
}

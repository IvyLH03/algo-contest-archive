#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,m,x,y;
long long a[N],t[4*N],z,d[4*N];
void mt(long long x,long long l,long long r)
{
	if(l==r)
	{
		t[x]=a[l];return;
	}
	int mid=l+(r-l>>1);
	mt(x<<1,l,mid);
	mt(x<<1|1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1|1];
}
void add(int k,long long v,int l,int r)
{
	d[k]+=v;
	t[k]+=v*(r-l+1);
}
void pushdown(int k,int l,int r)
{
	if(!d[k]) return;
	int mid=l+(r-l>>1);
	add(k<<1,d[k],l,mid);
	add(k<<1|1,d[k],mid+1,r);
	d[k]=0;
}
void change(int k,int l,int r)
{
	if(l>=x&&r<=y)
	{
		add(k,z,l,r);return;
	}
	pushdown(k,l,r); 
	int mid=l+(r-l>>1);
	if(x<=mid) change(k<<1,l,mid);
	if(y>mid)  change(k<<1|1,mid+1,r);
	t[k]=t[k<<1]+t[k<<1|1];
}

long long plus(int k,int l,int r)
{
	if(l>=x&&r<=y) return t[k];
	long long sum=0;
	pushdown(k,l,r);
	int mid=l+(r-l>>1);
	if(x<=mid) sum+=plus(k<<1,l,mid);
	if(y>mid)  sum+=plus(k<<1|1,mid+1,r);
	return sum;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j,k;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	mt(1,1,n);long long ans;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d%lld",&x,&y,&z);
			change(1,1,n); 
		}
		else
		{
			scanf("%d%d",&x,&y);
			ans=plus(1,1,n);
			printf("%lld\n",ans);
		}
	}
	return 0;
}

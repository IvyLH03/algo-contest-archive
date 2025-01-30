#include<cstdio>
using namespace std;
const int N=100007;
long long t[40*N],a[40*N],tagp[40*N],tagm[40*N],n,m,p;
void build(long long x,long long l,long long r)
{
	tagm[x]=1;
	if(l==r)
	{
		t[x]=a[l]%p;return;
	}
	long long mid=l+(r-l>>1);
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[x]=(t[x<<1]+t[x<<1|1])%p;
}
void pushdown(long long x,long long l,long long r)
{
	if(tagm[x]==1&&tagp[x]==0) return;
	long long mid=l+(r-l>>1);
	t[x<<1]=(t[x<<1]*tagm[x]+(mid-l+1)*tagp[x])%p;
	t[x<<1|1]=(t[x<<1|1]*tagm[x]+(r-mid)*tagp[x])%p;
	tagp[x<<1]=(tagp[x<<1]*tagm[x]+tagp[x])%p;
	tagp[x<<1|1]=(tagp[x<<1|1]*tagm[x]+tagp[x])%p;
	tagm[x<<1]=(tagm[x]*tagm[x<<1])%p;
	tagm[x<<1|1]=(tagm[x]*tagm[x<<1|1])%p;
	tagp[x]=0;
	tagm[x]=1;
}
void sum(long long x,long long l,long long r,long long v)
{
	t[x]+=(r-l+1)*v;t[x]%=p;
	tagp[x]+=v;tagp[x]%=p;
	pushdown(x,l,r);
}
void mult(long long x,long long l,long long r,long long v)
{
	tagp[x]*=v;tagm[x]*=v;t[x]*=v;
	tagp[x]%=p;tagm[x]%=p;t[x]%=p;
	pushdown(x,l,r);
}
void chgp(long long x,long long l,long long r,long long ll,long long rr,long long v)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		sum(x,l,r,v);return;
	}
	long long mid=l+(r-l>>1);
	pushdown(x,l,r);
	if(ll<=mid) chgp(x<<1,l,mid,ll,rr,v);
	if(rr>mid) chgp(x<<1|1,mid+1,r,ll,rr,v);
	t[x]=(t[x<<1]+t[x<<1|1])%p;
}
void chgm(long long x,long long l,long long r,long long ll,long long rr,long long v)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		mult(x,l,r,v);return;
	}
	long long mid=l+(r-l>>1);
	pushdown(x,l,r);
	if(ll<=mid) chgm(x<<1,l,mid,ll,rr,v);
	if(rr>mid) chgm(x<<1|1,mid+1,r,ll,rr,v);
	t[x]=(t[x<<1]+t[x<<1|1])%p;
}
long long query(long long x,long long l,long long r,long long ll,long long rr)
{
	if(l>rr||r<ll) return 0;
	if(l>=ll&&r<=rr)
		return t[x];
	pushdown(x,l,r);
	long long mid=l+(r-l>>1);
	return (query(x<<1,l,mid,ll,rr)+query(x<<1|1,mid+1,r,ll,rr))%p;
}
int main()
{
	scanf("%lld%lld",&n,&p);
	long long i,x,y,v;int k;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	scanf("%lld",&m);
	build(1,1,n);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%lld%lld%lld",&x,&y,&v);
			chgm(1,1,n,x,y,v);
		}
		else if(k==2)
		{
			scanf("%lld%lld%lld",&x,&y,&v);
			chgp(1,1,n,x,y,v);
		}
		else if(k==3)
		{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query(1,1,n,x,y)%p);
		}
	}
	return 0;
}

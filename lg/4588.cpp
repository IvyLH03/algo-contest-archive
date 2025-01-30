#include<cstdio>
#define mid (l+(r-l>>1))
using namespace std;
const int N=100007;
long long t[N<<2],mod,m;
int tag,T,q,k;
void build(int x,int l,int r)
{
	//printf("%d %d %d\n",x,l,r);
	t[x]=1;
	if(l==r) return;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void pushup(int x)
{
	t[x]=t[x<<1]*t[x<<1|1]%mod;
	return;
}
void modify(int x,int l,int r,int tar,long long v,bool flag)
{
	if(tar>r||tar<l)return;
	if(l==r&&l==tar)
	{
		if(flag) t[x]=v;
		else t[x]=1;
		return;
	} 
	if(tar<=mid) modify(x<<1,l,mid,tar,v,flag);
	if(tar>mid) modify(x<<1|1,mid+1,r,tar,v,flag);
	pushup(x);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		build(1,1,100006);
		scanf("%d%lld",&q,&mod);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&k,&m);
			if(k==1) modify(1,1,q,i,m,1);
			else modify(1,1,q,m,m,0);
			printf("%lld\n",t[1]);
		}
	}
	return 0;
}

#include<cstdio>
#include<algorithm>
#define mid (l+(r-l>>1))
using namespace std;
const int N=50007;
int n,m,t[N<<4],a[N],y[N];
void pushup(int x)
{
	t[x]=max(t[x<<1],t[x<<1|1]);
}
void build(int x,int l,int r)
{
	if(l==r) 
	{
		t[x]=a[l];return;
	}
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x);
}
int query(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return 0;
	if(l>=ll&&r<=rr) return t[x];
	int tmp=0;
	if(mid>=ll) tmp=query(x<<1,l,mid,ll,rr);
	if(mid<rr) tmp=max(tmp,query(x<<1|1,mid+1,r,ll,rr));
	return tmp; 
}
int findy(int x)
{
	if(x>y[n]) return n+1;
	int ans,l=1,r=n;
	while(l<=r)
	{
		if(y[mid]>=x) ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(y[ans]==x) return ans;
	return -1*ans;
} 
int check(int ly,int ry)
{
	bool unkl=0,unkr=0;
	int l=findy(ly),r=findy(ry);
	if(l<0) l=-1*l,unkl=1;
	if(r<0) r=-1*r,unkr=1;
	int maxn=query(1,1,n+1,l+(unkl^1),r-1); //如果左边不知道，那么会是在区间里的一个数；右面无论是否知道都在区间外； 
	if(!(unkl||unkr))
	{
		if(a[l]<a[r]) return -1;
		if(r==l+1&&ry==ly+1) return 1;
		if(r==l+1) return 0;
		if(maxn>=a[l]||maxn>=a[r]) return -1;
		if(l-r!=ly-ry) return 0;
		return 1;
	}
	else if(unkl&&(!unkr)&&maxn>=a[r]) return -1;
	else if(unkr&&(!unkl)&&maxn>=a[l]) return -1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&y[i],&a[i]);
	build(1,1,n+1);
	scanf("%d",&m);
	int ly,ry;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&ly,&ry);
		int k=check(ly,ry);
		if(k==1) printf("true\n");
		else if(k==0) printf("maybe\n");
		else printf("false\n");
	}
	return 0;
}

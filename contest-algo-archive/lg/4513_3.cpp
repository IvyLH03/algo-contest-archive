#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500007,INF=100007;
int n,m,lv[4*N],rv[4*N],t[4*N],v[4*N],a[N],res;
void pushup(int x,int l,int r)
{
	t[x]=t[x<<1]+t[x<<1|1];
	lv[x]=max(lv[x<<1],t[x<<1]+lv[x<<1|1]);
	rv[x]=max(rv[x<<1|1],rv[x<<1]+t[x<<1|1]);
	v[x]=max(max(v[x<<1],v[x<<1|1]),rv[x<<1]+lv[x<<1|1]);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		lv[x]=rv[x]=t[x]=v[x]=a[l];return;
	}
	int mid=l+(r-l>>1);
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	pushup(x,l,r);
}
void change(int x,int l,int r,int tar,int val) 
{
	if(l>tar||r<tar) return;
	if(l==r&&r==tar)
	{
		lv[x]=rv[x]=t[x]=v[x]=val;return;
	}
	int mid=l+(r-l>>1);
	if(mid>=tar) change(x<<1,l,mid,tar,val);
	else change(x<<1|1,mid+1,r,tar,val);
	pushup(x,l,r);
}
int query(int x,int l,int r,int ll,int rr,int typ)
{
//	if(l>rr||r<ll) return -INF;
	if(l==r) return t[x];//这两句都不是很清楚有没有必要写 
	int mid=l+(r-l>>1);	//事实证明觉得没必要的那句话有必要，觉得有必要的那句话没必要 
	if(typ==1)
	{
		if(l==ll&&r==rr) return v[x];
		if(mid>=rr) return query(x<<1,l,mid,ll,rr,1);
		if(mid<ll) return query(x<<1|1,mid+1,r,ll,rr,1);
		return max(max(query(x<<1,l,mid,ll,mid,1),query(x<<1|1,mid+1,r,mid+1,rr,1)),
					query(x<<1,l,mid,ll,mid,2)+query(x<<1|1,mid+1,r,mid+1,rr,3));
	} 
	if(typ==2)
	{
		if(mid+1==ll) return rv[x<<1|1];
		if(mid+1<ll) return query(x<<1|1,mid+1,r,ll,rr,2);
		return max(rv[x<<1|1],t[x<<1|1]+query(x<<1,l,mid,ll,mid,2));
	} 
	if(mid==rr) return lv[x<<1];
	if(mid>rr) return query(x<<1,l,mid,ll,rr,3);
	return max(lv[x<<1],t[x<<1]+query(x<<1|1,mid+1,r,mid+1,rr,3));
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,k,x,y,s;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&k,&x,&y);
		if(k==1) 
		{	
			if(x>y) swap(x,y);
			printf("%d\n",query(1,1,n,x,y,1));
		}
		else change(1,1,n,x,y);
	}
	return 0;
}

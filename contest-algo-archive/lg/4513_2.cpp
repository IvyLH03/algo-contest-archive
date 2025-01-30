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
	if(mid<tar) change(x<<1|1,mid+1,r,tar,val);
	pushup(x,l,r);
}
int query(int x,int l,int r,int ll,int rr,int rol)
{
	int mid=l+(r-l>>1),s=-INF; 
	if(!rol)
	{
		if(l==ll&&r==rr) return v[x];
		if(l>=ll&&r<=mid) return query(x<<1,l,mid,ll,rr,0);
		if(l>mid&&r<=rr) return query(x<<1|1,mid+1,r,ll,rr,0);
		if(l==ll&&r>mid) return max(v[x<<1],max(rv[x<<1]+query(x<<1|1,mid+1,r,mid+1,rr,1),query(x<<1|1,mid+1,r,mid+1,rr,0)));
		if(r==rr&&l<=mid) return max(query(x<<1,l,mid,ll,mid,0),max(query(x<<1,l,mid,ll,mid,2)+lv[x<<1|1],v[x<<1|1]));
		return max(max(query(x<<1,l,mid,ll,mid,0),query(x<<1|1,mid+1,r,mid+1,rr,0)),query(x<<1,l,mid,ll,mid,2)+query(x<<1|1,mid+1,r,mid+1,rr,1));
	}
	if(rol==1)
	{
		if(l==ll)
		{
			if(r==rr) return lv[x];
			if(rr==mid) return lv[x<<1];
			if(rr<mid) return query(x<<1,l,mid,ll,rr,1);
			return max(lv[x<<1],t[x<<1]+query(x<<1|1,mid+1,r,mid+1,rr,1));
		}
		if(r==rr)
		{
			if(ll==mid+1) return lv[x<<1|1];
			if(ll>mid+1) return query(x<<1|1,mid+1,r,ll,rr,1);
			return max(query(x<<1,l,mid,ll,mid,1),query(x<<1,l,mid,ll,mid,3)+lv[x<<1|1]);
		}
		return max(query(x<<1,l,mid,ll,mid,1),query(x<<1,l,mid,ll,mid,3)+query(x<<1|1,mid+1,r,mid+1,rr,1));
	}
	if(rol==2)
	{
		if(r==rr)
		{
			if(l==ll) return rv[x];
			if(ll==mid+1) return rv[x<<1|1];
			if(ll>mid+1) return query(x<<1|1,mid+1,r,ll,rr,2);
			return max(rv[x<<1|1],t[x<<1|1]+query(x<<1,l,mid,ll,mid,2));
		}
		if(l==ll)
		{
			if(rr==mid) return(rv[x<<1]);
			if(rr<mid) return query(x<<1,l,mid,ll,rr,2);
			return max(query(x<<1|1,mid+1,r,mid+1,rr,2),query(x<<1|1,mid+1,r,mid+1,rr,3)+rv[x<<1]);
		}
		return max(query(x<<1|1,mid+1,r,mid+1,rr,2),query(x<<1|1,mid+1,r,mid+1,rr,3)+query(x<<1,l,mid,ll,mid,2)); 
	}
	if(rol==3)
	{
		if(l>rr||r<ll) return 0;
		if(l>=ll&&r<=rr) return t[x];
		int s=0;
		if(mid>=ll) s+=query(x<<1,l,mid,ll,rr,3);
		if(mid<rr) s+=query(x<<1|1,mid+1,r,ll,rr,3);
		return s;
	}		
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
			printf("%d\n",query(1,1,n,x,y,0));
		}
		else change(1,1,n,x,y);
	}
	return 0;
}

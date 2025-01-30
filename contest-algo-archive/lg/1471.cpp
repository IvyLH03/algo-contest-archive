#include<cstdio>
using namespace std;
const int N=100007;
double t[4*N],a[N],laz[4*N],tp[4*N];
int n,m;
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=a[l];tp[x]=a[l]*a[l];
		return;
	}
	int mid=l+(r-l>>1);
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1|1];
	tp[x]=tp[x<<1]+tp[x<<1|1];
}
void pushdown(int x,int l,int r)
{
	if(!laz[x]) return;
	laz[x<<1]+=laz[x];
	laz[x<<1|1]+=laz[x];
	int mid=l+(r-l>>1);
	tp[x<<1]+=2*laz[x]*t[x<<1]+(mid-l+1)*laz[x]*laz[x];
	tp[x<<1|1]+=2*laz[x]*t[x<<1|1]+(r-mid)*laz[x]*laz[x];
	t[x<<1]+=laz[x]*(mid-l+1);
	t[x<<1|1]+=laz[x]*(r-mid);
	laz[x]=0;
}
void change(int x,int l,int r,int ll,int rr,double v)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		laz[x]+=v;
		tp[x]+=2*v*t[x]+(r-l+1)*v*v;
		t[x]+=v*(r-l+1);return;
	}
	int mid=l+(r-l>>1);
	pushdown(x,l,r);
	if(mid>=ll) change(x<<1,l,mid,ll,rr,v);
	if(mid<rr) change(x<<1|1,mid+1,r,ll,rr,v);
	t[x]=t[x<<1]+t[x<<1|1];
	tp[x]=tp[x<<1]+tp[x<<1|1];
}
double query(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return 0;
	if(l>=ll&&r<=rr) return t[x];
	int mid=l+(r-l>>1);double s=0;
	pushdown(x,l,r);
	if(mid>=ll) s=query(x<<1,l,mid,ll,rr);
	if(mid<rr) s+=query(x<<1|1,mid+1,r,ll,rr);
	return s;
}
double query2(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return 0;
	if(l>=ll&&r<=rr) return tp[x];
	pushdown(x,l,r);
	int mid=l+(r-l>>1);double s=0;
	if(mid>=ll) s=query2(x<<1,l,mid,ll,rr);
	if(mid<rr) s+=query2(x<<1|1,mid+1,r,ll,rr);
	return s;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j,k,x,y;double v;
	for(i=1;i<=n;i++)
		scanf("%lf",&a[i]);
	build(1,1,n);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)
		{
			scanf("%lf",&v); change(1,1,n,x,y,v);
		}
		else if(k==2)
		{
			printf("%.4lf\n",query(1,1,n,x,y)/(y-x+1));
		}
		else
		{
			double s1=query(1,1,n,x,y)/(y-x+1),s2=query2(1,1,n,x,y)/(y-x+1);//printf("s=%lf\n",s);
			printf("%.4lf\n",s2-s1*s1);
		}
	}
	return 0;
}

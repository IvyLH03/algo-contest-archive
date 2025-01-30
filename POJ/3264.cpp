#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200007,INF=100000007;
int tmax[4*N],tmin[4*N],v[N],n,m;
void build(int x,int l,int r)
{
	if(l==r)
	{
		tmax[x]=tmin[x]=v[l]; return;
	}
	int mid=l+(r-l>>1);
	build(x<<1,l,mid); build(x<<1|1,mid+1,r);
	tmax[x]=max(tmax[x<<1],tmax[x<<1|1]);
	tmin[x]=min(tmin[x<<1],tmin[x<<1|1]);
} 
int querymax(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return 0;
	if(l>=ll&&r<=rr) return tmax[x];
	int mid=l+(r-l>>1),res=0;
	if(mid>=ll) res=querymax(x<<1,l,mid,ll,rr);
	if(mid<rr) res=max(res,querymax(x<<1|1,mid+1,r,ll,rr));
	return res;
}
int querymin(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return INF;
	if(l>=ll&&r<=rr) return tmin[x];
	int mid=l+(r-l>>1),res=INF;
	if(mid>=ll) res=querymin(x<<1,l,mid,ll,rr);
	if(mid<rr) res=min(res,querymin(x<<1|1,mid+1,r,ll,rr));
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,x,y;
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	build(1,1,n);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",querymax(1,1,n,x,y)-querymin(1,1,n,x,y));
	}
	return 0;
}

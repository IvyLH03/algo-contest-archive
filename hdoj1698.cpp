#include<cstdio>
#include<cstring>
using namespace std;
const int N=100007;
int t[4*N],n,T,m,lazytag[4*N];
void build(int x,int l,int r)
{
	lazytag[x]=1;
	if(l==r)
	{
		t[x]=1;return;
	}
	int mid=l+(r-l>>1);
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1|1];
}
void pushdown(int x,int l,int r)
{
	if(!lazytag[x]) return;
	lazytag[x<<1]=lazytag[x];
	lazytag[x<<1|1]=lazytag[x];
	int mid=l+(r-l>>1);
	t[x<<1]=lazytag[x]*(mid-l+1);
	t[x<<1|1]=lazytag[x]*(r-mid);
	lazytag[x]=0;
}
void change(int x,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		lazytag[x]=v;t[x]=(r-l+1)*v;
		return;
	}
	pushdown(x,l,r);
	int mid=l+(r-l>>1);
	if(mid>=ll) change(x<<1,l,mid,ll,rr,v);
	if(mid<rr) change(x<<1|1,mid+1,r,ll,rr,v);
	t[x]=t[x<<1]+t[x<<1|1];
}
int main()
{
	scanf("%d",&T);
	int iiiii,i,x,y,v;
	for(iiiii=1;iiiii<=T;iiiii++)
	{
		scanf("%d%d",&n,&m);
		build(1,1,n);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&v);
			change(1,1,n,x,y,v);
		}
		printf("Case %d: The total value of the hook is %d.\n",iiiii,t[1]);
	}
	return 0;
}

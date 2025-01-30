#include<cstdio>				//不考虑复杂度的半暴力做法 
#include<algorithm>
using namespace std;
const int N=200007;
long long INF=-1<<61;
long long a[N],t[4*N],m,d,y,tot,r;
void change(int p,int v,int x,int l,int r) 
{
	if(l==r)
	{
		t[x]=v;return;
	}
	int mid=l+(r-l>>1);
	if(mid>=p) change(p,v,x<<1,l,mid);
	if(mid<p) change(p,v,x<<1|1,mid+1,r);
	t[x]=max(t[x<<1],t[x<<1|1]);
}
int query(int x,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr) return t[x];
	long long a=INF,b=INF;
	int mid=l+(r-l>>1);
	if(mid>=ll) a=query(x<<1,l,mid,ll,rr);
	if(mid<rr) b=query(x<<1|1,mid+1,r,ll,rr);
	return max(a,b);
}
int main()
{
	scanf("%lld%lld",&m,&d);
	int i,x;char c;
	for(i=1;i<=m;i++)
		a[i]=INF;
	for(i=1;i<=m;i++)
	{
		getchar();
		getchar();
		scanf("%c%d",&c,&x);
		if(c=='A')
		{
			change(++tot,(x+r)%d,1,1,m);
		}
		else
		{
			r=query(1,1,m,tot-x+1,tot)%d;
			printf("%lld\n",r);
		}
	}
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50007;
int t[4*N],y[N],v[N],n,m;
bool mabt[4*N],mab[N],flag;
void build(int x,int l,int r)
{
	if(l==r)
	{
		mabt[x]=mab[l];
		t[x]=v[l];
		return;
	}
	int mid=l+(r-l>>1);
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	t[x]=max(t[x<<1],t[x<<1|1]);
	if(mabt[x<<1]||mabt[x<<1|1]) mabt[x]=1;
}
int query(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return -1;
	if(l>=ll&&r<=rr) 
	{
		if(mabt[x]) flag=1;
		return t[x];
	}
	int mid=l+(r-l>>1),s=-1;
	if(mid>=ll) s=query(x<<1,l,mid,ll,rr);
	if(mid<rr) s=max(s,query(x<<1|1,mid+1,r,ll,rr));
	return s;
}
int find(int tar)
{
	int l=y[1],r=y[n],mid;
	while(l<=r)
	{
		mid=l+(r-l>>1);
		if(y[mid]==tar) return mid;
		else if(y[mid]<tar) l=mid+1;
		else r=mid-1;
	}
	return mid;
} 
int main()
{
	int i,j,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&y[i],&v[i]);
		if(y[i]!=y[i-1]+1) mab[i-1]=1;
	}
	build(1,1,n);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		flag=0;
		scanf("%d%d",&a,&b);
		if(a>b) 
		{
			printf("false\n");continue;
		}
		a=find(a);b=find(b);
		if(v[a]<v[b])
		{
			printf("false\n");continue;
		}
		if(query(1,1,n,a+1,b-1)<v[b])
		{
			if(flag) printf("maybe\n");
			else printf("true\n");
		}
		else printf("false\n");
	}
	return 0;
}

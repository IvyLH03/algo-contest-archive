#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200007;
struct node{
	char t;
	int l,r;
}q[2*N]; 
int m,n,t[4*N],tot,cnt,minl,maxr;
bool del[4*N],s[4*N];
void build(int x,int l,int r)
{
	s[x]=1;
	if(l==r) return;
	int mid=l+(r-l>>1);
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void pushdown(int x,int l,int r)
{
	s[x]=0;
	if(!t[x]) return;
	t[x<<1]=t[x<<1|1]=t[x];t[x]=0;
}
void find(int x,int l,int r,int v)
{
	if(s[x])
	{
		if(!del[t[x]]&&t[x])
		{					//		printf("*");
			tot--;cnt++;del[t[x]]=1;
		}
		t[x]=v;return;
	}
	t[x]=v;
	if(l==r) return;
	int mid=l+(r-l>>1);
	find(x<<1,l,mid,v);
	find(x<<1|1,mid+1,r,v);
	s[x]=v;
}
void change(int x,int l,int r,int ll,int rr,int v)
{						//	printf("*");
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr) 
	{					//	printf("*");
		find(x,l,r,v);return;
	}
	pushdown(x,l,r);
	int mid=l+(r-l>>1);
	if(mid>=ll) change(x<<1,l,mid,ll,rr,v);
	if(mid<rr) change(x<<1|1,mid+1,r,ll,rr,v);
}
int main()
{
	scanf("%d",&m);
	int i;minl=4*N;
	for(i=1;i<=m;i++)
	{
		getchar();//提交时用两个?
		getchar();
		scanf("%c",&q[i].t);
		if(q[i].t=='B') continue; 
		scanf("%d%d",&q[i].l,&q[i].r);
		minl=min(minl,q[i].l);
		maxr=max(maxr,q[i].r);
		n++;
	}
	build(1,minl,maxr);
							//		printf("\nminl=%d,maxr=%d\n",minl,maxr);
	for(i=1;i<=m;i++)
	{
		if(q[i].t=='A')
		{
			tot++;cnt=0;
			change(1,minl,maxr,q[i].l,q[i].r,i);
			printf("%d\n",cnt);
		}
		else printf("%d\n",tot);
	}
	return 0;
}

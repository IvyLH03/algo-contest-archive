#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000007;
long long Mod=99999997;
struct node{
	long long h;int num;
}a[N],b[N];
int n,c[N],ans,res[N];
bool cmp(node x,node y)
{
	return x.h<y.h;
}
long long rd()
{
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';c=getchar();
	}
	return x*f;
}
void msort(int l,int r)
{
	if(l==r) return;
	int mid=l+(r-l>>1);
	msort(l,mid);msort(mid+1,r);
	int p1=l,p2=mid+1,p3=l-1;
	while(p1<=mid&&p2<=r)
	{
		if(c[p1]>c[p2])
		{
			ans=(ans+mid-p1+1)%Mod;
			res[++p3]=c[p2++];
		}
		else res[++p3]=c[p1++];
	}
	while(p1<=mid) res[++p3]=c[p1++];
	while(p2<=r) res[++p3]=c[p2++];
	for(int i=l;i<=r;i++) c[i]=res[i];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) a[i].h=rd(),a[i].num=i;
	for(int i=1;i<=n;i++) b[i].h=rd(),b[i].num=i;
	sort(a+1,a+1+n,cmp);sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++) c[a[i].num]=b[i].num;
	msort(1,n); 
//	for(int i=1;i<=n;i++) printf("%d ",c[i]);printf("\n");
	printf("%d\n",ans);
	return 0;
}

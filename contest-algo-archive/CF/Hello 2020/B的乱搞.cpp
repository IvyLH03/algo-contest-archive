#include<cstdio> 
#include<algorithm>
using namespace std;
const int N=100007,INF=100000007;
int a[N],n,m,tot,maxn[N],minn[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) minn[i]=INF;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		bool flag=0;
		for(int j=1;j<=m;j++) 
		{
			scanf("%d",&a[j]);
			if(flag) continue;
			maxn[i]=max(a[j],maxn[i]);
			if(a[j]>minn[i]) 
			{
				flag=1;
			}
			minn[i]=min(a[j],minn[i]);
		}
		if(flag) 
		{
			ans+=(n-1)*2+1;
			maxn[i]=0;minn[i]=INF;
			n--,i--;
			continue;
		}
	}
//	sort(maxn+1,maxn+1+n,cmp);
	sort(minn+1,minn+1+n);
	for(int i=1;i<=n;i++)//在最小值里二分找有几个小于最大值的 
	{
		int l=1,r=n,mid,anstmp=0;
		while(l<=r)
		{
			mid=l+(r-l>>1);
			if(minn[mid]>=maxn[i]) r=mid-1; 
			else anstmp=mid,l=mid+1;
		}
		ans+=anstmp;
	}
	printf("%d\n",ans);
/*	for(int i=1;i<=n;i++)//在最大值里二分找有几个大于最小值的 
	{
		int l=1,r=n,mid,anstmp=0;
		while(l<=r)
		{
			mid=l+(r-l>>1);
			if(maxn[mid]<=minn[i]) r=mid-1; 
			else anstmp=mid,l=mid+1;
		}
		ans+=anstmp;
	} 
	printf("%d",ans);*/
	return 0;
}

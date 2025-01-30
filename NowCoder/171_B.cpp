#include<cstdio>
using namespace std;
int n,m,a[100007],b[100007],c,xuqiu,gonji;
long long ans;
bool flag;
int abs(int a)
{
	if(a<0)return -1*a;
	return a;
}
int main()
{
	int l=0,r=0,mid;
	int i,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{ 
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]/b[i]>r)
			r=a[i]/b[i];
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		c+=x;
	}					//printf("%d",r);
	
	ans=2147483647;r++;
	while(l<=r)
	{
		mid=(l+r)/2;
		xuqiu=0;
		gonji=mid*c;
		for(i=1;i<=n;i++)
		{
			if(a[i]>=b[i]*mid)
				xuqiu+=a[i]-b[i]*mid;
		}
		if(abs(gonji-xuqiu)<ans) 
			ans=abs(gonji-xuqiu);
		if(gonji<xuqiu)
			l=mid+1;
		if(gonji>xuqiu)
			r=mid-1;
		if(gonji==xuqiu)
			break;
		
	}
	printf("%lld",ans);
	return 0;
	
}

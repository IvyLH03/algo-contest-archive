#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,l[200001],r[200001];
long long w[200001],v[200001],f[200001][2],s,ans=999999999999999,sum;
int pd(long long mid)
{
	memset(f,0,sizeof(f));
	int i;
	for(i=1;i<=n;i++)
	{
		if(w[i]>=mid)
		{
			f[i][0]=f[i-1][0]+1; 
			f[i][1]=f[i-1][1]+v[i];
		}
		else
		{
			f[i][0]=f[i-1][0];
			f[i][1]=f[i-1][1];
		}
	}
	sum=0;
	for(i=1;i<=m;i++)
	{
		sum+=(f[r[i]][0]-f[l[i]-1][0])*(f[r[i]][1]-f[l[i]-1][1]);
	} 
	if(sum>s)
		return 1;
	if(sum==s)
		return 0;  
	return -1;
}
int main()
{
	scanf("%d%d%lld",&n,&m,&s);
	int i;
	long long y=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&w[i],&v[i]);
		y=max(y,w[i]);
	}
	for(i=1;i<=m;i++)
		scanf("%d%d",&l[i],&r[i]);
	long long z=0,mid;y+=2;
	while(z<y)
	{
		mid=(z+y)/2;
		int x=pd(mid);
		long long a=sum-s;
		if(a<0) a*=-1; 
		ans=min(ans,a);
		if(x==0)
		{
			printf("0");
			return 0;
		}
		else if(x==1)
				z=mid+1;
			else
				y=mid;
	}
	printf("%lld",ans);

	return 0;
}

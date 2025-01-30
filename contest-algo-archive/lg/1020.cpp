#include<cstdio>
#include<algorithm>
using namespace std;
int k[100001],ans,f[100001],a[100001];
int main()
{
	int n=0;
	while(scanf("%d",&a[++n]));
	n--;
	int i,j,maxn=1;
	f[n]=1;
	for(i=n-1;i>=1;i--)
	{
		for(j=n;j>i;j--)
			if(a[i]<=a[j])
				f[i]=max(f[i],f[j]+1);
		maxn=max(f[i],maxn);
	}
	printf("%d\n",maxn);
	
	int t=1;
	k[1]=a[1];
	for(i=2;i<=n;i++)
	{
		int minn=0;
		for(j=1;j<=t;j++)
		{
			if(k[j]>a[i])
			{
				if(!minn)
				{
					minn=j;
				}
				else if(k[j]<k[minn])
					minn=j;
			}
		}
		if(minn)
			k[minn]=a[j];
		else
			k[++t]=a[j];
	}
	printf("%d",t);
	return 0;
}

#include<cstdio>
#include<algorithm> 
using namespace std;
int a[100001],f[100001],k[100001],ans,maxx;
int main()
{
	int n=1,i,m=0;
	while(scanf("%d",&a[n++])==1)
	{
		maxx=0;
		f[n]=1;
		for(i=1;i<n;i++)
			if(a[i]>=a[n])
				if(f[i]>maxx)
					maxx=f[i];
		f[n]=maxx+1;
		ans=max(ans,f[n]);
		
		int minn=0;
		for(i=1;i<=m;i++)
			if(k[i]>=a[n])
			{
				if(minn==0)	minn=i;
				else minn=k[i]<minn? i:minn;
			}
		if(!minn)
		{
			m++;minn=m;
		}
		k[minn]=a[n];
	}
	printf("%d\n%d",ans,m);
}

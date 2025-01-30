#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long ans,n,m,a[31][31],f[31][31],temp;
long long _2pow(long long x)
{ 
	if(x==0) return 1;
	return 2*_2pow(x-1);
}
int main()
{
	long long i,j,k,len,temp;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%lld",&a[i][j]);
	
	for(k=1;k<=n;k++)
	{
		memset(f,0,sizeof(f));
	//	for(len=m-1;len>=0;len--)
	//		for(i=1;i+len<=m;i++)
			for(i=1;i<=m;i++)
			{
			//	j=i+len;
				for(j=m;j>=i;j--)
					f[i][j]=max(f[i-1][j]+a[k][i-1]*_2pow(m-j+i-1),f[i][j+1]+a[k][j+1]*_2pow(m-j+i-1));
			}
		temp=0;
		for(i=1;i<=m;i++)
			temp=max(temp,f[i][i]+a[k][i]*_2pow(m));
		
						//	printf("%d\n",temp);
		ans+=temp;
	}
	printf("%lld",ans);
	return 0;
}

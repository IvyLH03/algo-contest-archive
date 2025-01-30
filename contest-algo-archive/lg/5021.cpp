#include<cstdio>
#include<algorithm>	//只考虑b[i]=a[i]+1的情况，即是一条链 
using namespace std;
int n,m,l[50001];
bool pd(int x)
{
	int i,j=1,s=0;
	for(i=1;i<n;i++)
	{
		s+=l[i];
		if(s>=x)
		{
			if(j==m)
				return 1;
			s=0;j++;
		}
	}
	return 0;
} 
int main()
{
	int i,j,k,x,mid,z=10007,y=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&k,&j,&x);
		l[k]=x;
		y+=x; z=min(x,z);
	}
							//printf("%d %d\n",z,y);
	while(z<=y)
	{
		mid=(z+y)/2;			//printf("z=%d;y=%d;mid:%d\n",z,y,mid);
		if(pd(mid)) z=mid+1;
		else y=mid-1;
	}
	printf("%d",y);
	return 0;
	
}

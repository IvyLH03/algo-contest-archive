#include<cstdio>
#include<cstring>
using namespace std;
int l,n,m,d[50001],e[50001];
bool c[50001];
bool pd(int x)
{
	int a=0,i;
	memset(c,0,sizeof(c));
	for(i=0;i<=n;i++)
	{
		if(!c[i])
		{
			int y=e[i+1],z=i+1;
			while(y<x&&z<=n+1)
			{
				if(z==n+1)	return 0;
				a++;c[z]=1;
				y+=e[++z];
				if(a>m)	return 0;
			}
		}
	}
	return 1;
}
int main()
{
	int i,j;
	scanf("%d%d%d",&l,&n,&m);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		e[i]=d[i]-d[i-1];
	}
	e[n+1]=l-d[n];
	
	int z=1,y=l,mid;
	while(z<=y)
	{
		mid=(z+y)/2;
		if(!pd(mid)) y=mid-1;
		else z=mid+1;
	}
	printf("%d",y);
	return 0;
}

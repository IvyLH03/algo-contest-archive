#include<cstdio>
#include<cstring>
using namespace std;
int n,m,r[1000011],d[1000011],s[1000011],t[1000011],dif[1000011];
bool pd(int mid)
{
	int i;
	memset(dif,0,sizeof(dif));
	for(i=1;i<=mid;i++)
	{
		dif[s[i]]+=d[i];
		dif[t[i]+1]-=d[i];
	} 
	int a=0;
	for(i=1;i<=n;i++)
	{
		a+=dif[i];
		if(a>r[i])
			return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&r[i]);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&d[i],&s[i],&t[i]);
	if(!pd(m))
	{
		printf("0");
		return 0;
	}
	int z=1,y=m,mid;
	while(z<y)
	{
		mid=(z+y)/2;
		if(pd(mid))
			y=mid;
		else
			z=mid+1;
	}
	printf("-1\n%d",z);
	return 0;
}

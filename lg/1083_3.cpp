#include<cstdio>
#include<cstring>
using namespace std;
int n,m,r[100001],d[100001],s[100001],t[100001],f[100001];
bool pd(int mid)
{
	memset(f,0,sizeof(f));
	int i,j;
	for(i=1;i<=mid;i++)
	{
		f[s[i]]+=d[i];
		f[t[i]+1]-=d[i];
	}
	int a=0;
	for(i=1;i<=n;i++)
	{
		a+=f[i];
		if(a>r[i])
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
	} 
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&d[i],&s[i],&t[i]); 
	}
	int z=1,y=m,mid;
	if(pd(m))
	{
		printf("0");
		return 0;
	}
	while(z<y)
	{
		mid=(z+y)/2; 
		if(pd(mid))
			z=mid+1;
		else
			y=mid;
	} 
	printf("-1\n%d",z);
	return 0;
}

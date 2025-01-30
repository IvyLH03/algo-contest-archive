#include<cstdio>
#include<cstring>
using namespace std;
int n,m,r[1000001],d[1000001],s[1000001],t[1000001],dif[1000001];
bool pd(int x)
{
	int i;
	memset(dif,0,sizeof(dif));
	for(i=1;i<=x;i++)
	{
		dif[s[i]]+=d[i];
		dif[t[i]+1]-=d[i];
	}
	int a=0;
	for(i=1;i<=n;i++)
	{
		a+=dif[i];
		if(a>r[i]) return 1;
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
	
	int z=1,y=m,mid;
	if(!pd(m)){
		printf("0"); return 0;
	}
	while(z<y)
	{
		mid=(z+y)/2;
		if(pd(mid)) y=mid;
		else z=mid+1;
	}
	printf("-1\n%d",z);
	return 0;
}

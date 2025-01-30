#include<cstdio>
#include<algorithm>
using namespace std;
int phi[1000007],T,n[200007],p[1000007],ptot;
bool vis[1000007];
int main()
{
	int i,j,maxn=-1;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&n[i]);maxn=max(maxn,n[i]);
	}
	phi[1]=1;
	for(i=2;i<=maxn;i++)
	{
		if(!vis[i])
		{
			p[++ptot]=i;phi[i]=i-1;
		}
		for(j=1;j<=ptot;j++)
		{
			if(i*p[j]>maxn) break;
			if(vis[i*p[j]]) continue;
			vis[i*p[j]]=1;
			if(i%p[j]) phi[i*p[j]]=(p[j]-1)*phi[i];
			else phi[i*p[j]]=p[j]*phi[i];
		}
	}
	for(i=1;i<=T;i++)
		printf("%d\n",phi[n[i]]);
	return 0;
}

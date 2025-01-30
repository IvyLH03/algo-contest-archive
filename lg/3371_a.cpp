#include<cstdio>
#include<algorithm>
using namespace std;
int dis[10001],f[500001],g[500001],w[500001],first[10001],next[10001];
bool flag[10001];
int main()
{
	int n,m,s,i,j,k,minn=2147483647,u;
	scanf("%d%d%d",&n,&m,&s);
	for(i=1;i<=n;i++)
	{
		first[i]=-1;
		dis[i]=2147483647;
	}
	dis[s]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&f[i],&g[i],&w[i]);
		next[i]=first[f[i]];
		first[f[i]]=i;
		if(f[i]==s)
			dis[g[i]]=w[i];
	}
	for(i=1;i<=n-1;i++)
	{
		minn=2147483647;
		k=first[s];
		while(k!=-1)
		{
			if((!flag[g[k]])&&w[k]<minn)
			{
				minn=w[k];
				u=k;
			}
			k=next[k];
		}
					//	printf("7:%d\n",minn);
		flag[g[u]]=1;
		k=first[g[u]];
		while(k!=-1)
		{				
			if(dis[g[k]]>dis[g[u]]+w[k])
				dis[g[k]]=dis[g[u]]+w[k];
			k=next[k];
		}
	}
	for(i=1;i<=n;i++)
	{
		if(i==s)	printf("0 ");
		else printf("%d ",dis[i]);
	}
	return 0;
}

#include<cstdio>
using namespace std;
int first[101],next[101],u[101],v[101],w[101],dis[101],lv[101],vl[101];
const int inf=2000000;
bool flag[101];
int main()
{
	int lvd,n,m=0,i,j,k,a,b,ans=inf;
	scanf("%d%d",&lvd,&n);
	for(i=2;i<=n;i++)
		dis[i]=inf;
	for(i=1;i<=n;i++)
		first[i]=-1;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&vl[i],&lv[i],&a);
		for(j=1;j<=a;j++)
		{
			scanf("%d%d",&v[++m],&w[m]);
			u[m]=i;
			next[i]=first[i];
			first[i]=v[m];
		}
	}
	
	int minn;
	flag[1]=1;
	for(j=lv[1]-lvd;j<=lv[1];j++)
	{
		for(i=2;i<=n;i++)
			flag[i]=0,dis[i]=inf;
		for(i=1;i<=n;i++)
		{
			k=first[1];minn=inf;
			while(k!=-1)
			{
				if((!flag[k])&&w[k]<minn&&(lv[k]>=j)&&lv[k]<=j+lvd);
				{
					minn=w[k];
					a=k;
					dis[v[k]]=w[k];
				}
				k=next[k];
			}
			flag[a]=1;
			k=first[v[a]];
			while(k!=-1)
			{
				if(lv[k]<=j+lvd&&lv[k]>j)
					if(dis[v[k]]>dis[u[k]]+w[k])
					{
						dis[v[k]]=dis[u[k]]+w[k];
					}
			}
		}
		for(i=1;i<=n;i++)
			dis[i]+=v[i];
		minn=inf;
		for(i=2;i<=n;i++)
			if(dis[i]<minn)
				minn=dis[i];
		if(minn<ans)
			ans=minn;
	}
	printf("%d",ans);
	return 0;
} 

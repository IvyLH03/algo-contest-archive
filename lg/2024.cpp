#include<cstdio>
using namespace std;
const int N=100007;
int fa[N],e[N],f[N],n,k,ans;
int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int x,int y)
{
	x=find(x);y=find(y);
	fa[x]=y;
}
int main()
{
	scanf("%d%d",&n,&k);
	int i,s,x,y;
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=k;i++)
	{
		scanf("%d%d%d",&s,&x,&y);
		if(x>n||y>n)
		{
			ans++;continue;
		}
		if(s==1)
		{
			if(find(x)==find(y)) continue;
			if(((e[x])&&(find(e[x])==find(y)))||((e[y])&&(find(e[y])==find(x)))||(f[x]&&(find(f[x])==find(y)))||(f[y]&&(find(f[y])==find(x))))
			{
				ans++;continue;
			}
			unionn(x,y);
		}
		if(s==2)
		{
			if(find(x)==find(y)||(find()))
			{
				ans++;continue;
			}
			if(e[y]) unionn(e[y],x);
			else e[y]=x;
			if(f[x]) unionn(f[x],y);
			else f[x]=y;
		}
	}
	printf("%d",ans);
	return 0;
}

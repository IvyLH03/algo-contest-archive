#include<cstdio>
#include<algorithm>	//只考虑b[i]=a[i]+1||m=1的情况
using namespace std;
int n,m,l[50001],ans;
struct node{
	int num,f,s[50007],df;
}a[5000];
bool vis[5007];
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
void ac1()
{
	int i,j,k,x,mid,z=10007,y=0;
	
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&k,&j,&x);
		l[k]=x;
		y+=x; z=min(x,z);
	}
	while(z<=y)
	{
		mid=(z+y)/2;		
		if(pd(mid)) z=mid+1;
		else y=mid-1;
	}
	printf("%d",y);
}
void dfs(int x,int d)
{
	if(vis[x])
		return;
	ans=max(ans,d);
	if(!a[x].num)
		return;
	vis[x]=1;
	dfs(a[x].f,d+a[x].df);
	for(int i=1;i<=a[x].num;i++)
		dfs(a[x].s[i],d+a[a[x].s[i]].df);
	vis[x]=0;
	
}
void ac2()
{
	int i,j,k,x,y,z;

	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x].s[++a[x].num]=y;
		a[y].f=x;
		a[y].df=z;
	}
	
	for(i=1;i<=n;i++)
	{
		if(!a[i].num)
			dfs(a[i].f,a[i].df);
	}
	printf("%d",ans);
}
int main()
{
	scanf("%d%d",&n,&m);
	if(m==1) ac2();
	else ac1();
	return 0;
}

#include<cstdio>
using namespace std;
struct node{
	int to,next;	
}a[200005];
int indeg[100005],ans[100005],f[100005],head[100005];
bool vis[100005];
int max(int x,int y)
{
	return x>y? x:y;
} 
int main()
{
	int n,m,i,j,x,y,s=0,h=0,maxn=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		head[i]=-1;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[i].next=head[x];
		head[x]=i;
		a[i].to=y;
		indeg[y]++;
	}
	for(i=1;i<=n;)
	{
		for(j=1;j<=n;j++)
		{
			if(indeg[j]==0&&(!vis[j]))
			{
				vis[j]=1;
				ans[++h]=j;
				i++;	
			}
		}
		for(j=s+1;j<=h;j++)
		{
			x=head[ans[j]];
			while(x!=-1)
			{
				indeg[a[x].to]--;
				x=a[x].next;
			}
		}
		s=h;
	}
				//	printf("\n\n\ntp:\n");
    			//	for(i=1;i<=n;i++)
    			//		printf("%d ",ans[i]);
				//	printf("\n\n\n");
					
	for(i=1;i<=n;i++)
		f[i]=1;
	for(i=1;i<=n;i++)
	{
		x=head[ans[i]];
		while(x!=-1)
		{
			f[a[x].to]=max(f[a[x].to],f[ans[i]]+1);
			x=a[x].next;
		}
	}
	printf("%d",f[1]);
	for(i=2;i<=n;i++)
		printf("\n%d",f[i]);
	return 0;
} 

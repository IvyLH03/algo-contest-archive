#include<cstdio> 		//最大生成树+LCA求路径上最小边权
#include<algorithm>		//对不连通的情况加特判 （并查集） 
#include<queue>			//加了边权为0的读入特判 (然而还是没效果） 
using namespace std;
const int N=50007,INF=1e7;
queue<int>q;
struct node{
	int head,tail,v;
}a[2*N];
struct node2{
	int next,from,to,v;
}b[2*N];
int n,m,f[2*N],head[2*N],tot,fa[2*N][22],ans,MaxLoad[2*N][22],lg[22],depth[2*N];
bool vis[2*N];
void add(int x,int y)
{
	b[++tot].next=head[x];b[tot].from=x;
	b[tot].to=y;
	head[x]=tot;
}
int find(int x)
{
	if(f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
void unionn(int x,int y)
{
	x=find(x);y=find(y);
	f[y]=x;
}
bool comp(node x,node y)
{
	return x.v>y.v;
}
void Lca(int x,int y)
{
	int i;
	if(depth[x]>depth[y]) swap(x,y);
	for(i=20;i>=0;i--) 
	{	
		if(depth[fa[y][i]]>=depth[x])
		{
			ans=min(ans,MaxLoad[y][i]);
			y=fa[y][i]; 
		}
	}
	if(x==y) 
	{		
		return;
	}
	for(i=20;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			ans=min(ans,MaxLoad[x][i]);
			ans=min(ans,MaxLoad[y][i]);
			x=fa[x][i];y=fa[y][i];
		}
	}
	ans=min(ans,min(MaxLoad[x][0],MaxLoad[y][0]));
	//ans=min(ans,MaxLoad[y][0]);
	return;
}
void dfs(int f,int fath,int val)
{
	int i;
	vis[f]=1;
	fa[f][0]=fath;
	MaxLoad[f][0]=val;
	depth[f]=depth[fath]+1;
	i=head[f];
	while(i)
	{
		if(b[i].to!=fath)
			dfs(b[i].to,f,b[i].v);
		i=b[i].next;
	}
}
int main()
{
	int i,j,k,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{	
		scanf("%d%d%d",&a[i].head,&a[i].tail,&a[i].v);
		if(!a[i].v)
		{
			i--;m--;
		}
	}
							//		for(i=1;i<=m;i++)
								//		printf("case%d:x=%d,y=%d,v=%d\n",i,a[i].head,a[i].tail,a[i].v);
	sort(a+1,a+1+m,comp);
	for(i=1;i<=n;i++)
	{
		f[i]=i;		
	}
	for(i=1;i<=m;i++)
	{
		if(find(a[i].head)!=find(a[i].tail))
		{
			add(a[i].head,a[i].tail);add(a[i].tail,a[i].head);
			unionn(a[i].head,a[i].tail);b[tot].v=b[tot-1].v=a[i].v;
											if((!b[tot].v)||(!b[tot-1].v)) printf("*"); 
		}
	//	if(tot==n-1) break;			
	}								//		for(i=1;i<=tot;i++)
									//	printf("case%d:x=%d,y=%d,v=%d\n",i,b[i].from,b[i].to,b[i].v);
										
									//	for(i=1;i<=n;i++)
									//		printf("case%d:f[%d]=%d\n",i,i,find(i));
	
	for(i=1;i<=n;i++)		
	{
	//	if(head[i]&&(!vis[i]))
		if(!vis[i])
		{			//printf("*");
			dfs(i,0,INF);	//val=0和val=INF似乎没有什么区别 
			depth[i]=1;	 
		}
	}												
	

	for(i=1;i<=20;i++)
    {
        for(j=1;j<=n;j++)
        {
        	fa[j][i]=fa[fa[j][i-1]][i-1];
        	MaxLoad[j][i]=min(MaxLoad[j][i-1],MaxLoad[fa[j][i-1]][i-1]);
        }
    }
							//		for(i=1;i<=n;i++)
							//			printf("log[%d]=%d\n",i,lg[i]);
	int q;
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		ans=INF;
		scanf("%d%d",&x,&y);
										//	printf("depth[%d]=%d,depth[%d]=%d\n",x,depth[x],y,depth[y]); 
		if(find(x)!=find(y))
		{
			printf("%d\n",-1); continue;
		}
		Lca(x,y);
		printf("%d\n",ans);
	}								
										//	for(i=1;i<=n;i++)
										//		printf("case%d:f[%d]=%d\n",i,i,find(i));

	return 0;
}

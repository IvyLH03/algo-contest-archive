#include<cstdio> 		//���������+LCA��·������С��Ȩ
#include<algorithm>		//�Բ���ͨ����������� �����鼯�� 
#include<queue>			//�Ա�����������0 (Ȼ����ȫ��Ч�� 
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
	while(depth[y]>depth[x])
	{						//		printf("*");
		if(MaxLoad[y][lg[depth[y]-depth[x]]-1])ans=min(ans,MaxLoad[y][lg[depth[y]-depth[x]]-1]);
		y=fa[y][lg[depth[y]-depth[x]]-1]; 
	}
	if(x==y) return;
	for(i=lg[depth[x]]-1;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			if(MaxLoad[x][i])	ans=min(ans,MaxLoad[x][i]);
			if(MaxLoad[y][i])	ans=min(ans,MaxLoad[y][i]);
			x=fa[x][i];y=fa[y][i];
		}
	}
	if(MaxLoad[x][0])	ans=min(ans,MaxLoad[x][0]);
	if(MaxLoad[y][0])	ans=min(ans,MaxLoad[y][0]);
	return;
}
void dfs(int f,int fath,int val)
{
	int i;vis[f]=1;
	fa[f][0]=fath;MaxLoad[f][0]=val;
	depth[f]=depth[fath]+1;
	for(i=1;(1<<i)<=depth[f];i++)
	{
		fa[f][i]=fa[fa[f][i-1]][i-1];
		MaxLoad[f][i]=min(MaxLoad[fa[f][i-1]][i-1],MaxLoad[f][i-1]);
	}
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
		scanf("%d%d%d",&a[i].head,&a[i].tail,&a[i].v);
							//		for(i=1;i<=m;i++)
								//		printf("case%d:x=%d,y=%d,v=%d\n",i,a[i].head,a[i].tail,a[i].v);
	sort(a+1,a+1+m,comp);
	for(i=1;i<=n;i++)
		f[i]=i;							
	for(i=1;i<=m;i++)
	{
		if(find(a[i].head)!=find(a[i].tail))
		{
			add(a[i].head,a[i].tail);add(a[i].tail,a[i].head);
			unionn(a[i].head,a[i].tail);b[tot].v=b[tot-1].v=a[i].v;
		}
	//	if(tot==n-1) break;			
	}								//		for(i=1;i<=tot;i++)
									//	printf("case%d:x=%d,y=%d,v=%d\n",i,b[i].from,b[i].to,b[i].v);
										
									//	for(i=1;i<=n;i++)
									//		printf("case%d:f[%d]=%d\n",i,i,find(i));
	
	for(i=1;i<=n;i++)		
	{
		if(head[i]&&(!vis[i]))
		{			//printf("*");
			dfs(i,0,0);
		}
	}												
									//	for(i=1;i<=n;i++)
									//	{
									//		for(j=0;(1<<j)<=depth[i]-1;j++)
									//		{
									//				printf("%d��%d:%d\n",i,fa[i][j],MaxLoad[i][j]);
									//		}
									//	}

	for(i=1;i<=n;i++)
    {
        lg[i]=lg[i-1];
        if(1<<lg[i-1]==i) lg[i]++;
    }
							//		for(i=1;i<=n;i++)
							//			printf("log[%d]=%d\n",i,lg[i]);
	int q;
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		ans=INF;
		scanf("%d%d",&x,&y);
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

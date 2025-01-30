#include<cstdio>
#include<algorithm> 
const int N=500005;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
struct node{
	int next,to;
}a[4*N];
int fa[4*N][22],depth[4*N],head[4*N],n,m,num,s,lg[2*N];
void add(int x,int y)
{
	a[++num].next=head[x];
	a[num].to=y;
	head[x]=num;
}
void dfs(int f,int fath)
{
	depth[f]=depth[fath]+1;
	fa[f][0]=fath;
	int i;
	for(i=1;(1<<i)<=depth[f];i++)
		fa[f][i]=fa[fa[f][i-1]][i-1];
	i=head[f];
	while(i)
	{
		if(a[i].to!=fath)
			dfs(a[i].to,f);
		i=a[i].next;
	}
}
int LCA(int x,int y)
{
//	if(x==y) return x;
	int i;
	if(depth[x]>depth[y]) swap(x,y);
	while(depth[y]>depth[x])
		y=fa[y][lg[depth[y]-depth[x]]-1];
	if(x==y) return x;
	for(i=lg[depth[x]]-1;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];y=fa[y][i];
		}
	} 
	return fa[x][0];
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	int i,j,k;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		add(j,k);add(k,j);
	}
	dfs(s,0);
	for(i=1;i<=n;i++)
	{
		lg[i]=lg[i-1];
		if(1<<lg[i-1]==i) lg[i]++;
	}
		
										
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&j,&k);
		printf("%d\n",LCA(j,k));
	}
	return 0;
}

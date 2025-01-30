#include<cstdio>					//废案 
#include<algorithm>					//LCA部分需要写一种边建树边求LCA 
#include<queue>
using namespace std;
const int N=65537;
int depth[4*N],fa[4*N][22],lg[4*N],head1[4*N],head2[4*N],num1,num2,numt[4*N],tot,e[4*N],m,n,tp[4*N],sont[4*N];
struct node{
	int next,to;
}a[4*N],b[4*N];
void adda(int x,int y)
{
	a[++num1].next=head1[x];
	a[num1].to=y;e[y]++;
	head1[x]=num1;
}
void addb(int x,int y)
{
	b[++num2].next=head2[x];
	b[num2].to=y;
	head2[x]=num2;
}
queue<int>q;
void dfs(int f,int fath)
{
	depth[f]=depth[fath]+1;
	for(int i=1;(1<<i)<=depth[f];i++)
	{
		fa[f][i]=fa[fa[fath][i-1]][i-1];
	}
	int i=head1[f];
	while(i)
	{
		if(a[i].to!=fath)
			dfs(a[i].to,f);
		i=a[i].next;
	}
}
int Lca(int x,int y)
{
	if(depth[x]>depth[y]) swap(x,y);
	while(depth[y]>depth[x])
		y=fa[y][lg[depth[y]-depth[x]]-1];
	if(x==y) return x;
	for(int i=lg[depth[x]]-1;i>=0;i--)
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
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		while(j)
		{
			adda(j,i);sont[i]++;
			scanf("%d",&j);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!e[i])
		q.push(i);tp[++tot]=i;
	}
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		int i=head1[p];
		while(i)
		{
			e[a[i].to]--;
			if(!e[a[i].to])
			{
				q.push(a[i].to);
				tp[++tot]=a[i].to;
			}
			i=a[i].next;
		}
	}								//	printf("*");
	for(i=1;i<=n;i++)
		numt[i]=1;
	int lca;
	dfs(1,0);
	for(i=1;i<=n;i++)
	{
		lg[i]=lg[i-1];
		if((1<<i-1)==i) lg[i]++;
	}								//	printf("*");
															printf("\n");
															for(i=1;i<=n;i++)
																printf("%d ",tp[i]);
															printf("\n");
	for(i=1;i<=n;i++)
	{											//printf("*");
		if(!sont[i]) continue;
		if(sont[i]==1)
		{
			addb(i,a[head1[i]].to);addb(a[head1[i]].to,i);
			numt[a[head1[i]].to]++;continue;
		}
		j=head1[i];k=a[j].next;				//printf("*");
		while(k)
		{									//printf("*");
			lca=Lca(a[j].to,a[k].to);
			j=k;k=a[j].next;
		}
		addb(i,lca);addb(lca,i);
		numt[lca]++;
	}
	for(i=1;i<=n;i++)
		printf("%d\n",numt[i]);
	return 0;
}

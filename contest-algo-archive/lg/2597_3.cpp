#include<cstdio>
#include<algorithm>				//TLE 点1，点3; 
#include<queue>
using namespace std;
const int N=65537;
int depth[40*N],fa[40*N][22],lg[40*N],head1[40*N],tail[40*N],head2[40*N],num1,num2,numt[40*N],tot,e[40*N],m,n,tp[40*N],sont[40*N];
struct node{
	int next,to,nextt,from;
}a[40*N],b[40*N];
void adda(int x,int y)			//加个tail 
{
	a[++num1].next=head1[x];a[num1].nextt=tail[y];
	a[num1].to=y;e[x]++;a[num1].from=x;
	head1[x]=num1;tail[y]=num1;
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
	int i; 
	depth[f]=depth[fath]+1;
	fa[f][0]=fath;
	for(i=1;(1<<i)<=depth[f];i++)
	{
		fa[f][i]=fa[fa[f][i-1]][i-1];
	}
	//numt[fath]++;
	i=head2[f];					//	printf("case %d:head2[%d].to=%d\n",f,f,b[head2[f]].to);
	while(i)
	{							// printf("*");
		numt[b[i].to]++;
		i=head2[b[i].to];
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
		if(fa[x][i]&&fa[y][i]&&fa[x][i]!=fa[y][i])
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
			adda(i,j);sont[i]++;
			scanf("%d",&j);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(!e[i])
		{					//	printf("*");
			q.push(i);tp[++tot]=i;
		}
	}
	while(!q.empty())
	{					//		printf("*");
		int p=q.front();
		q.pop();
		int i=tail[p];
		while(i)
		{					//	printf("*");
			e[a[i].from]--;
			if(!e[a[i].from])
			{
				q.push(a[i].from);
				tp[++tot]=a[i].from;
			}
			i=a[i].nextt;
		}
	}								//	printf("*");
								//	printf("\ntp:");
								//	for(i=1;i<=n;i++)
								//		printf("%d ",tp[i]);
							//		printf("\n");

	int lca;
	for(i=1;i<=n;i++)
	{
		lg[i]=lg[i-1];
		if((1<<i-1)==i) lg[i]++;
	}
	//dfs(tp[1],0); 
	for(i=1;i<=n;i++)
	{			
		int p=tp[i]	;						
		if(!sont[p])
		{									//	printf("case%d:lca=0\n",i);
			dfs(p,0);continue;					
		}
		if(sont[p]==1)
		{									//	printf("case%d:lca=%d\n",i,a[head1[p]].to);
			addb(p,a[head1[p]].to);//addb(a[head1[p]].to,p);
			dfs(p,a[head1[p]].to);continue;		
		}
		j=head1[p];k=a[j].next;
		while(k)
		{									//printf("*");
			lca=Lca(a[j].to,a[k].to);
			j=k;k=a[j].next;
		}
		addb(p,lca);//addb(lca,p);			//	printf("case%d:lca=%d\n",i,lca) ;
		dfs(p,lca);
	}
	for(i=1;i<=n;i++)
		printf("%d\n",numt[i]);
	return 0;
}

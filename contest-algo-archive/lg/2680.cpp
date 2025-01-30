#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=300007;
int v[N],fa[N][21],size[N],dep[N],cnt[N],depv[N],n,m,qtot,etot;
struct node{
	int next,to,v;
}e[2*N];
struct node2{
	int from,to,len,lca;
}que[2*N];
int head[N],maxe;
void adde(int x,int y,int v)
{
	e[++etot].next=head[x];
	e[etot].to=y;
	head[x]=etot;
	e[etot].v=v;
}
void addq(int x,int y,int v,int lca)
{
	que[++qtot].from=x;
	que[qtot].to=y;
	que[qtot].len=v;
	que[qtot].lca=lca;
}
void dfs1(int x,int f,int y)
{
	dep[x]=dep[f]+1;fa[x][0]=f;	
	depv[x]=depv[f]+e[y].v;v[x]=e[y].v;
	int i;size[x]=1;
	for(i=1;i<=20;i++)
	{
		if(!fa[fa[x][i-1]][i-1]) continue;
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs1(e[i].to,x,i);
		size[x]+=size[e[i].to];
	}

}
bool comp(node2 x,node2 y)
{
	return x.len>y.len;
}

void dfs2(int x,int f)
{
	if(size[x]==1)	return;
	int i;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs2(e[i].to,x);
		cnt[x]+=cnt[e[i].to];
	}
}
bool pd(int mid)
{
	memset(cnt,0,sizeof(cnt));
	int j=0,i;maxe=0;
	while(que[++j].len>mid)
	{
		cnt[que[j].from]++;cnt[que[j].to]++;
		cnt[que[j].lca]-=2;
	}
	j--;dfs2(1,0);
	for(i=1;i<=n;i++)
		if(cnt[i]==j) maxe=max(maxe,v[i]);
	if(que[1].len-maxe>mid) return 0;
	return 1;
	
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int i;
	for(i=20;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];y=fa[y][i];
		}
	return fa[x][0];
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,x,y,z,maxl=-1;
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		adde(x,y,z);adde(y,x,z);
	}
	dfs1(1,0,0);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		z=lca(x,y);
		int len=depv[x]+depv[y]-2*depv[z];
		addq(x,y,len,z);
		maxl=max(maxl,len);
	}
	sort(que+1,que+1+m,comp);
	int l=0,r=maxl,mid;
	int ans;
	while(l<=r)
	{
		mid=l+(r-l>>1);
		if(pd(mid))
		{
			r=mid-1;ans=mid;
		}
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}


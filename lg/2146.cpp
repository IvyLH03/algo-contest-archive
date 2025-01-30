#include<cstdio>
#include<algorithm>
using namespace std;
const int N=400007;
int at[N],fa[N],son[N],dep[N],size[N],top[N],head[N],etot,atot,t[4*N],lazytag[4*N],num[4*N],n,q,res;
bool vis[N];
char s[20];
struct node{
	int next,to;
}e[N];
void pt()
{
	for(int i=1;i<=13;i++) printf("%d ",t[i]);
	printf("\n");
}
void adde(int x,int y)
{
	e[++etot].next=head[x];
	e[etot].to=y;
	head[x]=etot;
}
void dfs1(int x,int f)
{			
	fa[x]=f;dep[x]=dep[f]+1;
	size[x]=1;int i,maxs=-1;
	for(i=head[x];i;i=e[i].next)
	{
		dfs1(e[i].to,x);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>maxs)
		{
			maxs=size[e[i].to];son[x]=e[i].to;
		}
	}
}
void dfs2(int x,int t)
{				
	top[x]=t;at[x]=++atot;
	if(!son[x]) return;
	dfs2(son[x],t);
	int i;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==son[x]) continue;
		dfs2(e[i].to,e[i].to);
	}
}
void pushdown(int x,int l,int r)//不知道有没有用……
{
	if(!t[x])
	{
		t[x<<1]=0;t[x<<1|1]=0;return;
	}
	if(t[x]!=(r-l+1)) return;
	int mid=l+(r-l>>1);
	t[x<<1]=mid-l+1;
	t[x<<1|1]=r-mid;
} 
void inst(int x,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
	{				//	printf("l=%d,r=%d\n",l,r);
		if(t[x]==(r-l+1)) return;
		res+=(r-l+1-t[x]);
		t[x]=r-l+1;pushdown(x,l,r);
		for(int i=l;i<=r;i++) vis[i]=1;
		return;
	}
	if(l>rr||r<ll) return;
	pushdown(x,l,r);
	int mid=l+(r-l>>1);
	if(mid>=ll) inst(x<<1,l,mid,ll,rr);
	if(mid<rr) inst(x<<1|1,mid+1,r,ll,rr);
	t[x]=t[x<<1]+t[x<<1|1];
}
void unin(int x,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
	{				//	printf("l=%d,r=%d\n",l,r);
		if(!t[x])
			return;
		res+=t[x];
		t[x]=0;pushdown(x,l,r);
		for(int i=l;i<=r;i++) vis[i]=0;
		return;
	}
	if(l>rr||r<ll) return;
	pushdown(x,l,r);
	int mid=l+(r-l>>1);
	if(mid>=ll) unin(x<<1,l,mid,ll,rr);
	if(mid<rr) unin(x<<1|1,mid+1,r,ll,rr);
	t[x]=t[x<<1]+t[x<<1|1];
}
void quei(int x)
{
	res=0;
	while((!vis[at[x]])&&x)
	{	
		inst(1,1,n,at[top[x]],at[x]);
		x=fa[top[x]];
	}
}
void queu(int x)
{
	res=0;
	if(!vis[at[x]])
		return;
	unin(1,1,n,at[x],at[x]+size[x]-1);
}
int main()
{
	scanf("%d",&n);
	int i,x;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);x++;
		adde(x,i);
	}
	dfs1(1,0);dfs2(1,1);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%s%d",s,&x);x++;
		if(s[0]=='i') quei(x);
		else queu(x);
		printf("%d\n",res);
	}
	return 0;
}

#include<cstdio>	//注意：可能有负值 
#include<algorithm>
using namespace std;
const int N=200007;
long long ts[N],tm[N];
int v[N],vt[N],dep[N],fa[N],son[N],size[N],top[N],at[N],lazytag[N];
char s[10];
struct node{
	int next,to;
}e[N];
int head[N],n,q,etot,atot;

void adde(int x,int y)
{
	e[++etot].next=head[x];
	e[etot].to=y;
	head[x]=etot;
}

void dfs1(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x]=f;
	size[x]=1;int i,maxs=-1;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
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
	vt[atot]=v[x];
	if(!son[x]) return;
	dfs2(son[x],t);
	int i;
	for(i=head[x];i;i=e[i].next)
	{
		if(e[i].to==fa[x]||e[i].to==son[x]) continue;
		dfs2(e[i].to,e[i].to);
	}
}

void build1(int x,int l,int r)
{
	if(l==r)
	{
		tm[x]=vt[l];return;
	}
	int mid=l+(r-l>>1);
	build1(x<<1,l,mid);
	build1(x<<1|1,mid+1,r);
	tm[x]=max(tm[x<<1],tm[x<<1|1]);
}

void build2(int x,int l,int r)
{
	if(l==r)
	{
		ts[x]=vt[l];return;
	}
	int mid=l+(r-l>>1);
	build2(x<<1,l,mid);
	build2(x<<1|1,mid+1,r);
	ts[x]=ts[x<<1]+ts[x<<1|1];
}


bool flag;		//写main函数的时候要记得初始化flag 
void change(int x,int l,int r,int t,int v)	
{
	if(flag) return;
				//	printf("*");
	if(l==r&&l==t)
	{
		tm[x]=v;ts[x]=v;
		flag=1;return;
	}
	if(l>t||r<t) return;
	int mid=l+(r-l>>1);
	if(mid>=t) change(x<<1,l,mid,t,v);
	else change(x<<1|1,mid+1,r,t,v);
	tm[x]=max(tm[x<<1],tm[x<<1|1]);
	ts[x]=ts[x<<1]+ts[x<<1|1];
}

int findmax(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return -N;
	if(l>=ll&&r<=rr) return tm[x];
	int mid=l+(r-l>>1),ans=-N;
	if(mid>=ll) ans=findmax(x<<1,l,mid,ll,rr);
	if(mid<rr) ans=max(ans,findmax(x<<1|1,mid+1,r,ll,rr));
	return ans;
}

int findsum(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return 0;
	if(l>=ll&&r<=rr) return ts[x];
	int mid=l+(r-l>>1),ans=0;
	if(mid>=ll) ans=findsum(x<<1,l,mid,ll,rr);
	if(mid<rr) ans+=findsum(x<<1|1,mid+1,r,ll,rr);
	return ans;
}

int query1(int x,int y)
{
	int ans=-N;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=max(ans,findmax(1,1,n,at[top[x]],at[x]));
		x=fa[top[x]];
	}
	if(at[x]>at[y]) swap(x,y);
	return max(ans,findmax(1,1,n,at[x],at[y]));
}

int query2(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans+=findsum(1,1,n,at[top[x]],at[x]);
		x=fa[top[x]];
	}
	if(at[x]>at[y]) swap(x,y);
	return ans+findsum(1,1,n,at[x],at[y]);
}

int main()
{
	scanf("%d",&n);
	int i,k,x,y;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	}
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	dfs1(1,0);
	dfs2(1,1);
	build1(1,1,n);
	build2(1,1,n);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='C')
		{
			flag=0;
			change(1,1,n,at[x],y);
		}
		else if(s[1]=='M')
		{
			printf("%d\n",query1(x,y));
		}
		else if(s[1]=='S')
		{
			printf("%d\n",query2(x,y));
		}
	}
	return 0;
}

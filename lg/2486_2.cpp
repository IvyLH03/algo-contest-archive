#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100007;
int n,m,af[N],a[N],nw[N],atot,etot,head[N],dep[N],fa[N],top[N],siz[N],t[N<<2],tl[N<<2],tr[N<<2],son[N],
	resl,resr;
bool al[N<<2];
struct node{
	int next,to;
}e[N<<1];
int Rd()
{
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';c=getchar();
	}
	return x*f;
}
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	head[x]=etot;
}
void dfs1(int x,int f)
{
	fa[x]=f;siz[x]=1;
	dep[x]=dep[f]+1;
	int maxs=0;
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs1(e[i].to,x);
		siz[x]+=siz[e[i].to];
		if(siz[e[i].to]>maxs) son[x]=e[i].to,maxs=siz[e[i].to];
	} 
}
void dfs2(int x,int topf)
{
	top[x]=topf;nw[x]=++atot;
	a[atot]=af[x];
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].to==fa[x]||e[i].to==son[x]) continue;
		dfs2(e[i].to,e[i].to);
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=1;tl[x]=tr[x]=a[l];
		return;
	}
	int mid=l+(r-l>>1);
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	t[x]=t[x<<1]+t[x<<1|1];
	if(tl[x<<1|1]==tr[x<<1]) t[x]--;
	tl[x]=tl[x<<1];tr[x]=tr[x<<1|1];
}
void pushdown(int x)
{
	if(t[x]>1) return;
	t[x<<1]=t[x<<1|1]=1;
	tl[x<<1]=tr[x<<1]=tl[x<<1|1]=tr[x<<1|1]=tl[x];
}
void pushup(int x)
{
	t[x]=t[x<<1]+t[x<<1|1];
	if(tl[x<<1|1]==tr[x<<1]) t[x]--;
	tl[x]=tl[x<<1];tr[x]=tr[x<<1|1];
}
void change(int x,int l,int r,int ll,int rr,int v)
{
	if(l>rr||r<ll) return;
	if(l>=ll&&r<=rr)
	{
		t[x]=1;tl[x]=tr[x]=v;
		return;
	}
	pushdown(x);
	int mid=l+(r-l>>1);
	if(mid>=ll) change(x<<1,l,mid,ll,rr,v);
	if(mid<rr) change(x<<1|1,mid+1,r,ll,rr,v);
	pushup(x);
}
int query(int x,int l,int r,int ll,int rr)
{
	if(l>rr||r<ll) return 0;
	if(l>=ll&&r<=rr)
	{
		if(l==ll) resl=tl[x];
		if(r==rr) resr=tr[x];
		return t[x];
	}
	pushdown(x);
	int mid=l+(r-l>>1),s=0;
	if(mid>=ll)  s=query(x<<1,l,mid,ll,rr);
	if(mid<rr) s+=query(x<<1|1,mid+1,r,ll,rr);
	if(mid>=ll&&mid<rr) 
	{
		if(tl[x<<1|1]==tr[x<<1]) s--;
	}
	pushup(x);
	return s;
}
void caddq(int x,int y,int v)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		change(1,1,n,nw[top[x]],nw[x],v);
		x=fa[top[x]];
	}
	if(nw[x]>nw[y]) swap(x,y);
	change(1,1,n,nw[x],nw[y],v);
}
int qaddq(int x,int y)
{
	int s=0,resx=0,resy=0;
	while(top[x]!=top[y])
	{
		resl=resr=0;
		if(dep[top[x]]>=dep[top[y]])
		{
			s+=query(1,1,n,nw[top[x]],nw[x]);
			if(resr==resx&&resx) s--;
			resx=resl;
			x=fa[top[x]];
		}
		else
		{
			s+=query(1,1,n,nw[top[y]],nw[y]);
			if(resr==resy&&resy) s--;
			resy=resl;
			y=fa[top[y]];
		}
	}
	if(dep[x]>dep[y])
	{
		s+=query(1,1,n,nw[y],nw[x]);
		if(resl==resy&&resy) s--;
		if(resr==resx&&resx) s--;
	}
	else if(dep[y]>dep[x])
	{
		s+=query(1,1,n,nw[x],nw[y]);
		if(resl==resx&&resx) s--;
		if(resr==resy&&resy) s--;
	}
	else
	{
		s+=query(1,1,n,nw[x],nw[y]);
		if(resl==resx&&resx) s-=2;
	}
	return s;
}
int main()
{
	int x,y,v;char c;
	n=Rd(),m=Rd(); 
	for(int i=1;i<=n;i++) af[i]=Rd();
	for(int i=1;i<n;i++)
	{
		x=Rd(),y=Rd();
		adde(x,y);adde(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%c",&c);
		if(c=='C')
		{
			x=Rd(),y=Rd(),v=Rd();
			caddq(x,y,v);
		}
		if(c=='Q')
		{
			x=Rd(),y=Rd();
			printf("%d\n",qaddq(x,y));
		}
	}
	return 0;
 } 

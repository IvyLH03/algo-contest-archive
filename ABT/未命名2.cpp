#include<bits/stdc++.h>
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define pi std::pair<int,int>
#define reg register
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN=6e5+5;
int A[MN],Map[MN],fMap[MN];
struct Mapper
{
    int fa[MN],L[MN],R[MN],suf[MN];//next
    void init(int N)
    {
        reg int i;
        for(i=1;i<=N;++i) fa[i]=L[i]=R[i]=i,suf[i]=-1;
    }
    int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
    void insert(int x,int y)
    {
        x=getf(x);y=getf(y);
        if(x==y) return;
        suf[R[x]]=L[y];
        L[y]=L[x];fa[x]=y;
    }
    bool vis[MN];
    void getMap(int N)
    {
        memset(vis,0,sizeof vis);
        reg int i,l,r,cnt=0;
        for(i=1;i<=N;++i)if(!vis[i])
            for(l=L[getf(i)];l>0;l=suf[l]) vis[fMap[++cnt]=l]=true;
        for(i=1;i<=N;++i) Map[fMap[i]]=i;
    }
}a;
struct Operation{int opt,x,y;}O[MN];
int readchar()
{
    static char s[5];
    scanf("%s",s+1);
    if(s[1]=='U') return 1;
    if(s[1]=='A') return 1+s[2]-'0';
    if(s[1]=='F') return 4+s[2]-'0'; 
}
struct Union_Find
{
    int fa[MN],L[MN],R[MN];
    void init(int N)
    {
        reg int i;
        for(i=1;i<=N;++i) fa[i]=i,L[i]=R[i]=Map[i];
    }
    int getf(int x)
    {
        return fa[x]==x?x:fa[x]=getf(fa[x]);
    }
    void combine(int x,int y)
    {
        x=getf(x);y=getf(y);if(x==y) return;
        fa[x]=y;L[y]=min(L[y],L[x]);R[y]=max(R[x],R[y]);
    }
    pi get(int x)
    {
        x=getf(x);
        return make_pair(L[x],R[x]);
    }
}b;
struct SegTree
{
    #define ls x<<1
    #define rs x<<1|1
    #define mid ((l+r)>>1)
    int t[MN<<2],lazy[MN<<1];
    void up(int x){t[x]=max(t[ls],t[rs]);}
    void Build(int x,int l,int r)
    {
        if(l==r) return (void)(t[x]=A[fMap[l]]);
        Build(ls,l,mid);Build(rs,mid+1,r);up(x);
    }
    void C(int x,int val){t[x]+=val,lazy[x]+=val;}
    void down(int x){if(lazy[x])C(ls,lazy[x]),C(rs,lazy[x]),lazy[x]=0;}
    void Modify(int x,int l,int r,int a,int b,int val)
    {
        if(l==a&&r==b) return (void)(C(x,val));down(x);
        if(b<=mid) Modify(ls,l,mid,a,b,val);
        else if(a>mid) Modify(rs,mid+1,r,a,b,val);
        else Modify(ls,l,mid,a,mid,val),Modify(rs,mid+1,r,mid+1,b,val);
        up(x);
    }
    int Query(int x,int l,int r,int a,int b)
    {
        if(l==a&&r==b) return t[x];down(x);
        if(b<=mid) return Query(ls,l,mid,a,b);
        else if(a>mid) return Query(rs,mid+1,r,a,b);
        else return max(Query(ls,l,mid,a,mid),Query(rs,mid+1,r,mid+1,b));
    }
}c;
int main()
{
    reg int i,N=read(); a.init(N);
    for(i=1;i<=N;++i) A[i]=read();
    reg int M=read();
    for(i=1;i<=M;++i)
    {
        O[i].opt=readchar();
        if(O[i].opt<7) O[i].x=read();
        if(O[i].opt<4) O[i].y=read();
        if(O[i].opt==1) a.insert(O[i].x,O[i].y);
    }
    a.getMap(N);c.Build(1,1,N);b.init(N);pi xxx;
    for(i=1;i<=M;++i)
    {
        if(O[i].opt==1) b.combine(O[i].x,O[i].y);
        if(O[i].opt==2) c.Modify(1,1,N,Map[O[i].x],Map[O[i].x],O[i].y);
        if(O[i].opt==3) xxx=b.get(O[i].x),c.Modify(1,1,N,xxx.first,xxx.second,O[i].y);
        if(O[i].opt==4) c.Modify(1,1,N,1,N,O[i].x);
        if(O[i].opt==5) printf("%d\n",c.Query(1,1,N,Map[O[i].x],Map[O[i].x]));
        if(O[i].opt==6) xxx=b.get(O[i].x),printf("%d\n",c.Query(1,1,N,xxx.first,xxx.second));
        if(O[i].opt==7) printf("%d\n",c.Query(1,1,N,1,N));
    }
    return 0;
}

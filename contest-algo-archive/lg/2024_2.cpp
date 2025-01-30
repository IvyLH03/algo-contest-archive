#include<cstdio>
using namespace std;
const int N=100007;
int fa[N],e[N],f[N],n,k,ans;
int find(int x)
{
    if(fa[x]==x) return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void unionn(int x,int y)
{
	if((!x)||(!y)) return;
    x=find(x);y=find(y);
    fa[x]=y;
}
int main()
{
    scanf("%d%d",&n,&k);
    int i,s,x,y;
    for(i=1;i<=n;i++)
    	fa[i]=i;
    for(i=1;i<=k;i++)
    {
        scanf("%d%d%d",&s,&x,&y);
        if(x>n||y>n)
        {
            ans++;continue;
        }
        if(s==1)
        {
            if(((e[x])&&(find(e[x])==find(y)))||((e[y])&&(find(e[y])==find(x))))
            {
                ans++;continue;
            }
            if(((f[x])&&(find(f[x])==find(y)))||((f[y])&&(find(f[y])==find(x))))
            {
                ans++;continue;
            }
          //  if(e[x]&&f[y]&&(find(e[x])==find(f[y])))
          //  {
          //  	ans++;continue;
            //}
          //  if(f[x]&&e[y]&&(find(f[x])==find(e[y])))
          //  {
         //   	ans++;continue;
         //   }
            unionn(x,y);
			if(e[x]&&e[y]) unionn(e[x],e[y]);
			else if(e[x]) e[y]=e[x];
			else if(e[y]) e[x]=e[y]; 
			if(f[x]&&f[y]) unionn(f[x],f[y]);
			else if(f[x]) f[y]=f[x];
			else if(f[y]) f[x]=f[y];
        }
        if(s==2)
        {
            if(find(x)==find(y)||(find(e[x])==find(y)))
            {
                ans++;continue;
            }						//x³Ôy 
          	if(e[x]&&f[y]) unionn(e[x],f[y]);
          	else if(e[x]) f[y]=e[x];
          	else if(f[y]) e[x]=f[y];
          	if(f[x]&&e[y]) unionn(f[x],e[y]);
          	else if(f[x]) e[y]=f[x];
          	else if(e[y]) f[x]=e[y];
          	unionn(f[x],y);unionn(e[y],x);
            
        }
    }
    printf("%d",ans);
    return 0;
}

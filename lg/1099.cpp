#include<cstdio>
#include<algorithm>
using namespace std;
const int N=301;
int n,s,val[N],head[N],etot,dep[N],f[N];
bool isdia[N];
struct edge
{
	int to,nxt,v;
}e[N<<1];
void adde(int x,int y,int v)
{
	e[++etot].to=y;
	e[etot].nxt=head[x];
	head[x]=etot;
}
void dfs1(int x,int fa)
{
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==fa) continue;
		dis[x]=dis[fa]+e[i].v;
		dep[x]=dep[fa]+1;
		f[x]=fa;
		dfs(e[i].to,x);
	}
}




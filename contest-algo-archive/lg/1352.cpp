#include<cstdio>
using namespace std;
const int N=6007;
int head[N],etot,n,r[N],f[N][2],rt;
bool hasf[N];
struct node{
	int nxt,to;
}e[N<<1];
void adde(int son,int fa)
{
	e[++etot].to=son;
	e[etot].nxt=head[fa];
	head[fa]=etot;
}
void dfs(int x)
{
	f[x][0]=0;f[x][1]=r[x];
	for(int i=head[x];i;i=e[i].nxt)
	{
		dfs(e[i].to);
		f[x][0]+=f[e[i].to][0]>f[e[i].to][1]?f[e[i].to][0]:f[e[i].to][1];
		f[x][1]+=f[e[i].to][0];
	}
}
int main()
{
	scanf("%d",&n);int fa,son;
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&son,&fa);
		adde(son,fa);hasf[son]=1;
	 } 
	for(int i=1;i<=n;i++)
		if(!hasf[i])
		{
			rt=i;break;
		}
	dfs(rt);
	printf("%d",f[rt][0]>f[rt][1]?f[rt][0]:f[rt][1]);
	return 0;
}

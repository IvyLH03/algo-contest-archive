//用f[i][0]表示不选i时，全覆盖其下面的边最少要选几个点
//用f[i][1]表示选择i时，全覆盖其下面的边最少要选几个点
//f[i][0]=∑f[son][1]
//f[i][1]=1+∑min(f[son][0],f[son][1])
//初始化:所有f[x][1]=1; 
#include<cstdio>
using namespace std;
const int INF=2147483647,N=1507;
struct node{
	int nxt,to;
}e[N<<1];
int n,head[N],etot,f[N][2];
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].nxt=head[x];
	head[x]=etot;
 } 
void dfs(int x,int fa)
{
	f[x][1]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==fa) continue;
		dfs(e[i].to,x);
		f[x][0]+=f[e[i].to][1];
		f[x][1]+=f[e[i].to][1]<f[e[i].to][0]?f[e[i].to][1]:f[e[i].to][0];
	}
	//if(f[x][0]==0) f[x][0]=INF; 
}
int main()
{
	scanf("%d",&n);int x,k,y;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&k);
		while(k--)
		{
			scanf("%d",&y);
			adde(x,y);adde(y,x);
		}
	}
	dfs(0,-1);
	printf("%d",f[0][0]>f[0][1]?f[0][1]:f[0][0]);
	return 0;
	
}

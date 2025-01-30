#include<cstdio>
#include<algorithm>
using namespace std;
const int N=37;
int n,etot,head[N],que[N],m,d[N],d2[N],cnt,tp[N];
bool vis[N][N];
struct edge{
	int x,y;
}e2[N];
struct node{
	int next,to;
}e[N];
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	head[x]=etot;
	d2[y]++;
}
bool topo()
{
	int t=1,w=0;bool flag=0;cnt=0;
	for(int i=1;i<=n;i++)
	{
		d[i]=d2[i];tp[i]=0;
		if(!d[i]) 
		{
			que[++w]=i;
		}
	}
	while(t<=w)
	{
		if(w-t>=1) flag=1;
		tp[++cnt]=que[t];
		for(int i=head[que[t]];i;i=e[i].next)
		{
			d[e[i].to]--;
			if(!d[e[i].to]) que[++w]=e[i].to;
		}
		t++;
	}
	if(cnt==n&&flag) return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	char s[10];
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		if(s[0]==s[2])
		{
			printf("Inconsistency found after %d relations.",i);
			return 0;
		}
		
		if(!vis[s[0]-'A'+1][s[2]-'A'+1])
		{
			adde(s[0]-'A'+1,s[2]-'A'+1);
			vis[s[0]-'A'+1][s[2]-'A'+1]=1;
		}
		if(!topo()) continue;
		
		else if(cnt<n)
		{
			printf("Inconsistency found after %d relations.",i);
			return 0;
		}
		else if(cnt==n)
		{
			printf("Sorted sequence determined after %d relations: ",i);
			for(int j=1;j<=n;j++) printf("%c",tp[j]+'A'-1);
			printf(".");return 0;
		}
	}
	printf("Sorted sequence cannot be determined.");
	return 0;
}

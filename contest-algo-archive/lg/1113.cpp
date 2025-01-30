#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100007;
int n,head[N],etot,que[N],t,w,ti[N],d[N],s[N];
bool vis[N];
struct node{
	int next,to;
}e[N];
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	head[x]=etot;
	d[y]++;
}
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&ti[i],&y);
		while(y)
		{
			adde(y,x);
			scanf("%d",&y);
		}
	}
	t=1;
	for(int i=1;i<=n;i++)
	{
		if(!d[i]) que[++w]=i;
	}
	while(t<=w)
	{
		for(int i=head[t];i;i=e[i].next)
		{
			s[e[i].to]=max(s[e[i].to],ti[t]);
			d[e[i].to]--;
			if(!d[e[i].to])
			{
				ti[e[i].to]+=s[e[i].to];
				que[++w]=e[i].to;
			}
		}
		t++;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,ti[i]);
	printf("%d",ans);
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;
const int N=207;
bool f[N][N];
struct edge{
	int to,next;
}e[N<<1];
int head[N<<1],num1[N<<1],num2[N<<1],n,etot,atot,t,m,fa[N<<1];
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int x,int y)
{
	int x1=find(x),x2=find(y);
	num1[x1]+=num1[x2];num2[x1]+=num2[x2];
	num1[x2]=0;num2[x2]=0;
	fa[x2]=x1;
}
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	head[x]=etot;
}
int main()
{
	int r;scanf("%d",&r);
	while(r--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) 
		{
			fa[i]=i;fa[i+200]=i+200;
			num1[i]=1;num1[i+200]=0;
			num2[i]=0;num2[i+200]=1;
		}
		int x,y;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);y+=200;
			if(find(x)!=find(y))
				unionn(x,y);
		}
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			if(num1[i]||num2[i])
			{
				for(int j=n;j>=num1[i];j--)
					for(int k=n;k>=num2[i];k--)
						if(f[j-num1[i]][k-num2[i]]) f[j][k]=1;
			}
			if(num2[i+200])
			{
				for(int j=n;j>=0;j--)
					for(int k=n;k>=num2[i+200];k--)
						if(f[j][k-num2[i+200]]) f[j][k]=1;
			}
			
		}
		for(int i=n/2;i>=0;i--)
			if(f[i][i]) 
			{
				printf("%d\n",i);break;
			}
	}
	return 0;
}

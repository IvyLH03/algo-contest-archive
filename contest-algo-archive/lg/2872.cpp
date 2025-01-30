#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1007;
int n,m,x[N],y[N],fa[N],etot,cnt;
double ans;
double getdis(int x,int y,int z,int w)
{
	return sqrt(((double)(x-z)*(x-z))+((double)(y-w)*(y-w)));
} 
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int x,int y)
{
	fa[find(x)]=find(y);
}
struct edge{
	int x,y;double v;
	/*friend bool operator < (edge a,edge b)
	{
		return a.v>b.v;
	}*/
}e[N*N];
void adde(int a,int b)
{
	e[++etot].x=a;
	e[etot].y=b;
	e[etot].v=getdis(x[a],x[b],y[a],y[b]);
}
bool cmp(edge a,edge b)
{
	return a.v<b.v;
}
int main()
{
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d%d",&x[i],&y[i]);
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		unionn(a,b);cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(find(i)==find(j)) continue; 
			//q.push((edge){a,b,getdis(x[a],x[b],y[a],y[b])});
			adde(i,j);printf("i=%d,j=%d,v=%.2lf\n",i,j,e[etot].v);
		}
	}
	sort(e+1,e+etot+1,cmp);
	int t=1;
	while(cnt<=n-2)
	{
		//edge e=q.top();q.pop();
		//if(find(e.x)==find(e.y)) continue;
		//ans+=e.v;unionn(e.x,e.y);
		//cnt++;
		if(find(e[t].x)!=find(e[t].y)) 
		{
			cnt++;ans+=e[t].v;unionn(e[t].x,e[t].y);
			printf("%d %d %.2lf\n",e[t].x,e[t].y,e[t].v);
		}
		t++;
	}
	printf("%lf",ans);
	return 0;
}

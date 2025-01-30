#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int u,v,w;
}a[200005]; 
int father[5005];
int find(int x)
{
	if(father[x]!=x)
		return find(father[x]);
	return x;
} 
void unionn(int a,int b)
{
	int x=find(a),y=find(b);
	father[y]=x;
}
bool comp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
	int n,m,i,tot=0,ans=0,x,y;
	bool flag=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(i=1;i<=n;i++)
		father[i]=i;
	sort(a+1,a+1+m,comp);
	for(i=1;i<n;i++)
	{
		flag=0;
		while(!flag)
		{
			x=a[++tot].u;
			y=a[tot].v;
			if(find(x)!=find(y))
			{
				flag=1;
				ans+=a[tot].w;
				unionn(x,y);
			}
		}
	}
	printf("%d",ans);
	return 0;
}

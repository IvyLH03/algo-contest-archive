#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
const int N=1007;
double dis(ll x1,ll y1,ll z1,ll x2,ll y2,ll z2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}
int t,n,h,r,fa[N],p1,p2,q1[N],q2[N];
ll x[N],y[N],z[N];
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		p1=p2=0;
		scanf("%d%d%d",&n,&h,&r);
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
			scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
			for(int j=1;j<i;j++)
				if(dis(x[i],y[i],z[i],x[j],y[j],z[j])<=2*r&&find(i)!=find(j))
					fa[find(i)]=find(j);
			if(z[i]-r<=0) q1[++p1]=i;
			if(z[i]+r>=h) q2[++p2]=i;
		} 
		bool flag=0;
		for(int i=1;i<=p1&&flag==0;i++)
			for(int j=1;j<=p2&&flag==0;j++)
				if(find(q1[i])==find(q2[j]))
				{ 
					flag=1;break;
				}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans;
struct node{
	int a,b,m;
}z[5001];
bool comp(node i,node j)
{
	return i.a<j.a;
}
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d%d",&z[i].a,&z[i].b);
	sort(z+1,z+1+n,comp);
	z[n].m=1;
	for(i=n;i>=1;i--)
	{
		for(j=i-1;j>=1;j--)
		{
			if(z[j].b<z[i].b)
				z[j].m=max(z[j].m,z[i].m+1);
		}
	}
	ans=z[1].m;
	for(i=1;i<=n;i++)
		if(z[i].m>ans)
			ans=z[i].m;
	printf("%d",ans);
	return 0;
}
 

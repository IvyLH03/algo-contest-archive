//luogu P1417 Åëµ÷·½°¸ 
#include<cstdio>
#include<algorithm>
using namespace std;
long long t,n,f[100001],ans;
struct node{
	long long a,b,w;
}obj[51];
bool comp(node x,node y)
{
	return x.w*y.b<y.w*x.b;
}
int main()
{
	int i,j;
	
	scanf("%d%d",&t,&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&obj[i].a);
	for(i=1;i<=n;i++)
		scanf("%lld",&obj[i].b);
	for(i=1;i<=n;i++)
		scanf("%lld",&obj[i].w);
	
	sort(obj+1,obj+1+n,comp);
	
	for(i=1;i<=n;i++)
		for(j=t;j>=obj[i].w;j--)
			if(f[j]<f[j-obj[i].w]+(obj[i].a-(j*obj[i].b)))
				f[j]=f[j-obj[i].w]+(obj[i].a-(j*obj[i].b));
			
	for(i=0;i<=t;i++)
		ans=max(ans,f[i]);
	
	printf("%lld",ans);
	return 0;
			
	
}

#include<cstdio>
#include<cmath>
#include<algorithm>
const int N=100007;
using namespace std;
int a[N],ans,andn,orn,n;
int dfs(int t,int anst,int l,int r)
{
	if(t=-1) return anst;
	int andt=a[l],ort=a[l];for(int i=l+1;i<=r;i++) andt&=a[i],ort|=a[i];
	if(andt&(1<<t)==ort&(1<<t)) dfs(t-1,anst,l,r);
	int p=l;
	while(a[p]&(1<<t)==0&&p<r) p++;
	return min(dfs(t-1,anst+(1<<t),l,p-1),dfs(t-1,anst+(1<<t),p,r));
}
int main()
{
	scanf("%d%d",&n,&a[1]);
	andn=a[1],orn=a[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		andn&=a[i];orn|=a[i];
	}
	sort(a+1,a+1+n);
	int t=30;while(orn&(1<<t)==0) t--;
	printf("%d",dfs(t,0,1,n));
	return 0;
}

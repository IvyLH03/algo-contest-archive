#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k,a[3507],t;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		if(k>=m) k=m-1;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int p1=1,p2=n;
		for(int i=1;i<=k;i++)
		{
			if(a[p1]<a[p2]) p1++;
			else p2--;
		}
		printf("p1=%d,p2=%d\n",p1,p2);
		int ans1=1000000007,ans2=1000000007;
		for(int i=p1;i<=p1+m-k-1;i++) ans1=ans1<a[i]?ans1:a[i];
		for(int i=p2;i>=p2-m+k+1;i--) ans2=ans2<a[i]?ans2:a[i];
		printf("%d\n",ans1>ans2?ans1:ans2);
	}
	return 0;
}

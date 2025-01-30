#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=100007;
struct node{
	int x,y,s;
	friend bool operator < (const node a,const node b)
	{
		if(a.s!=b.s) return a.s>b.s;
		if(a.x!=b.x) return a.x>b.x;
		return a.y>b.y;
	}
};
priority_queue<node>q;
int a[N],b[N],n,ans[N],cnt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	q.push((node){1,1,a[1]+b[1]});
	int x,y;
	while(cnt<n)
	{
		while(q.top().x==x&&q.top().y==y) q.pop();
		x=q.top().x,y=q.top().y;
		ans[++cnt]=q.top().s;q.pop();
		q.push((node){x+1,y,a[x+1]+b[y]});
		q.push((node){x,y+1,a[x]+b[y+1]});
	}
	sort(ans+1,ans+1+n);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}

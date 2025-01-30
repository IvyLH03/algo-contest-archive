#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int a[10001];
bool comp(int i,int j)
{
	return i>j;
}
priority_queue<int>q;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
	for(int i=1;i<=m&&i<=n;i++)
		q.push(-a[i]);
	if(n<=m)
	{		//	printf("7.");
		for(int i=1;i<q.size();i++)
			q.pop();
		printf("%d",-q.top());
	}
	
	int s;
//
//	sort(a+1+m,a+1+n,comp);
	for(int i=m+1;i<=n;i++)
	{
		s=q.top();
		q.pop();
		s-=a[i];
		q.push(s);
	}
			//	printf("%d",q.size());
	int b=q.size();
	for(int i=1;i<b;i++)
	{		//	printf("%d\n",q.top());
		q.pop();
	}
	printf("%d",-q.top());
	return 0;
	
} 

#include<cstdio>
#include<queue>
using namespace std;
int n,a;
priority_queue<int>q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		q.push(-a);
	}
	
	int x,y,s=0;
	while(q.size()>1)
	{
		x=q.top();
		q.pop();
		y=q.top();
		q.pop();
		q.push(x+y);
		s+=-(x+y);
	}
	
	printf("%d",s);
	return 0;
		
}

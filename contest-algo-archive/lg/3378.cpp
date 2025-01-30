#include<cstdio>
#include<queue>
using namespace std;
int n,k,a;
priority_queue<int>q;
int main()
{
	scanf("%d\n",&n);
	while(n--)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d",&a);q.push(-a);
		}
		else if(k==2) printf("%d\n",-q.top());
		else q.pop();
	}
	return 0;
}

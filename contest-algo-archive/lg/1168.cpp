#include<cstdio>
#include<queue>
using namespace std;
int n,a,k;
priority_queue<int>q1;
priority_queue<int>q2;
int main()
{
	scanf("%d%d",&n,&k);
	printf("%d\n",k);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a);
		if(a<k) q1.push(a);
		else q2.push(-a);
		if(i%2)
		{
			int s1=q1.size(),s2=q2.size();
			while(s1>s2)
			{
				q2.push(-k);k=q1.top();q1.pop();
				s1--;s2++;
			}
			while(s2>s1)
			{
				q1.push(k);k=-q2.top();q2.pop();
				s2--;s1++;
			}
			printf("%d\n",k);
		}
		
	}
	return 0;
}

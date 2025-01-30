#include<cstdio>
using namespace std;
int cx[1001],stack[1001];
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&cx[i]);
	int top=0,cur=1;
	for(i=1;i<=n;i++)
	{
		while(cur<=cx[i])
			stack[++top]=cur++;
		if(stack[top]==cx[i])
			--top;
		else
		{
			printf("NO");
			return 0;
		}
		
	}
	printf("YES");
	return 0;	
}

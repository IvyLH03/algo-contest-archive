#include<cstdio>
using namespace std;
int a[101];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int x=a[1]%2;bool flag=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]%2!=x) flag=1;
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

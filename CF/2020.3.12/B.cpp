#include<cstdio>
using namespace std;
int a[5007];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);bool flag=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n<3)
		{
			printf("NO\n");continue;
		}
		for(int i=1;i<=n-2;i++)
			for(int j=i+2;j<=n;j++)
				if(a[i]==a[j]) flag=1;
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

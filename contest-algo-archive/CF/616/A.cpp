#include<cstdio>
using namespace std;
int a[3001];
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		int k=0,sum=0;
		scanf("%d",&n);
		char c=getchar();
		while(c>'9'||c<'0') c=getchar();
		for(int i=1;i<=n;i++)
		{
			a[i]=c-'0';c=getchar();
		}
		while(a[n]%2==0&&n>0) a[n]=0,n--;
		if(n==0)
		{
			printf("-1\n");continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]%2&&k==0) k=i;
			sum+=a[i];
		}
		if(sum%2==0)
		{
			for(int i=1;i<=n;i++) printf("%d",a[i]);
		}
		if(sum%2==1&&k!=0&&k!=n) 
		{
			if(k==1)
			{
				int i=2;while(a[i]==0&&i<=n) i++;
				if(i>n) printf("-1");
				else for(;i<=n;i++) printf("%d",a[i]);
			}
			else for(int i=1;i<=n;i++)
			{
				if(i!=k) printf("%d",a[i]);
			}
		}
		if(sum%2==1&&(k==n||k==0)) printf("-1");
		printf("\n");
	}
	return 0;
 } 

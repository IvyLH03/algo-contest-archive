#include<cstdio>
using namespace std;
int ans0,ans1,ans2,n,t,x,m;
int main()
{
	ans1=1;ans2=2;
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(j=1;j<=m;j++)
		{
			scanf("%d%d",&t,&x);
			if(t==0)
			{
				ans0+=x;ans1+=x;ans2+=x;
			}
			if(t==1)
			{
				ans0*=x;ans1*=x;ans2*=x;
			}
			if(t==2)
			{
				ans0%=x;ans1%=x;ans2%=x;
			}
			
		}
		if(ans0==ans1&&ans0==ans2)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

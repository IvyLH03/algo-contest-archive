#include<cstdio>
using namespace std;
int n,td[201][201],maxn[201],a[201],ans,lj[201];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int x,y,i,j,t,ans=0;
	while(scanf("%d%d",&x,&y))
	{
		if(x==0&&y==0)
			break;
		td[x][y]=1;
	}
	maxn[n]=a[n];
	lj[n]=0;
	for(i=n-1;i>=1;i--)
	{
		maxn[i]=a[i]; 
		for(j=i+1;j<=n;j++)
		{
			if((td[i][j])&&(a[i]+maxn[j]>maxn[i]))
			{
				maxn[i]=a[i]+maxn[j];
				lj[i]=j;
			}
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		if(maxn[i]>ans)
		{
			ans=maxn[i];
			t=i;
		}
	}
	printf("%d",t);
	t=lj[t];
	while(t!=0)
	{
		printf("-%d",t);
		t=lj[t];
	}
	printf("\n%d",ans);
	return 0;
} 

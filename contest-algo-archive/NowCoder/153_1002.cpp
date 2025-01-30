#include<cstdio>
using namespace std;
int n,q,bm[1001],xq[1001][2];
int pow(int b)
{
	if(b==0)
		return 1;
	else 
		return 10*pow(b-1);
}
int main()
{
	scanf("%d%d",&n,&q);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&bm[i]);
	for(i=1;i<=q;i++)
		scanf("%d%d",&xq[i][1],&xq[i][2]);
	
	int ans;
	for(i=1;i<=q;i++)
	{
		ans=10000001;
		for(j=1;j<=n;j++)
		{
			if(bm[j]%pow(xq[i][1])==xq[i][2]&&bm[j]<ans)
				ans=bm[j];
		}
		if(ans==10000001)
			ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}

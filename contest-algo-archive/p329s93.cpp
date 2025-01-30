#include<cstdio>
//#include<algorithm>
using namespace std;
int a[200][3];
int main()
{
	int n,i,j,l,k,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i][1]);
		a[i][2]=1;a[i][3]=0;
	}
	for(i=n-1;i>=1;i--)
	{ 
		l=0;k=0;
		for(j=i+1;j<=n;j++)
			if((a[j][1]>a[i][1])&&(a[j][2]>l))
			{
				l=a[j][2];
				k=j;
			}
		if(l)
		{
			a[i][2]=l+1;a[i][3]=k; 
		}
	}
	k=1;
	for(i=1;i<=n;i++)
	{
		//if(a[i][2]>ans)
		//{
		//	ans=a[i][2];
		//	k=i;
		//}
		if(a[i][2]>a[k][2])
			k=i;
	}
	//printf("max=%d\n",ans);
	printf("max=%d\n",a[k][2]);
	while(k)
	{
		printf("%d ",a[k][1]);
		k=a[k][3];
	}
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct node{
	int d,num;
}a[1000001];
int d[1000001];
bool comp(node x,node y)
{
	return x.d<y.d;
}
int main()
{
	int i,j,tot=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i]==d[i-1])
		{
			i--;n--;
			continue;
		}
		a[i].d=d[i];a[i].num=i;
	}
	sort(a+1,a+1+n,comp);
						//for(i=1;i<=n;i++)
						//	printf("%d ",a[i].d);
						//printf("\n");
						//for(i=1;i<=n;i++)
						//	printf("%d ",d[a[i].num]);
						//printf("\n***\n");
	
	for(i=1;i<=n;i++)
	{
		if(d[a[i].num]!=0)
		{
			while(d[a[i].num])
			{
				tot++;
				for(j=a[i].num;j<=n;j++)
				{
					if(!d[j])
						break;
					d[j]--;
				}
				for(j=a[i].num-1;j>=1;j--)
				{
					if(!d[j])
						break;
					d[j]--;
				}
			}
		}
	}
	printf("%d",tot);
	return 0;
}

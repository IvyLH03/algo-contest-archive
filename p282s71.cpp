#include<cstdio>
using namespace std;
int n,m,a[110000];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=-1;
	for(int i=1;i<=m;i++)
	{
		int x;
		int left=1,right=n,mid;
		scanf("%d",&x);
		while(left<=right)
		{
			mid=(left+right)/2;
			if(a[mid]<=x)
				left=mid+1;
			else
				right=mid-1;
		}
		printf("%d\n",right);
	}
	return 0;
}

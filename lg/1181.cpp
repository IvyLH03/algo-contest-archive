#include<cstdio>
using namespace std;
int a[100001],tot=1,sum;
int main()
{
	int n,g;
	scanf("%d%d",&n,&g);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(sum+a[i]>g)
		{
			sum=0;
			tot++;
		}
		sum+=a[i];
	}
	printf("%d",tot);
	return 0;
}

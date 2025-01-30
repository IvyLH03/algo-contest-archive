#include<cstdio>
using namespace std;
int a[100001];
int main()
{
	int n,tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<=n;j++)
			if(a[i]>a[j])
				tot++;
	}
	printf("%d",tot);
	return 0;

}

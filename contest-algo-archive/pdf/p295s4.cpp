#include<cstdio>
using namespace std;
int a[100001];
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int t=1,mid,tot=0;
	while(t<n)
	{
		for(int i=t+1;i<=n;i++)
		{
			if(a[i]<a[t])
				tot++;
		}
		t++;
	}
	printf("%d",tot);
	return 0;
} 

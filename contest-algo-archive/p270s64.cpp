#include<cstdio>
using namespace std;
int a[1001],l[1001];
int main()
{
	int n=0;
	while((scanf("%d",&a[++n])));
	int k=1,p;
	l[k]=a[1];
	for(int i=2;i<=n;i++)
	{
		p=0;
		for(int j=1;j<=k;j++)
			if(l[j]>=a[i])
			{
				if(p==0)p=j;
				else if(l[p]>l[j])
					p=j;
			}
		if(p==0)
			l[++k]=a[i];
		else 
			l[p]=a[i];
	}
	printf("%d",k);
	return 0;
}

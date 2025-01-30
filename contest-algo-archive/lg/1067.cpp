#include<cstdio>
using namespace std;
int n,a[102];
int main()
{
	scanf("%d",&n);
	int i;
	for(i=n;i>=0;i--)
		scanf("%d",&a[i]);
	if(a[n]!=1&&a[n]!=-1)
		printf("%d",a[n]);
	if(a[n]==-1)
		printf("-");
	printf("x^%d",n);
	for(i=n-1;i>=1;i--)
	{
		if(a[i]==0)
			continue; 
		if(a[i]>0)
			printf("+");
		if(a[i]==-1)
			printf("-"); 
		if(a[i]!=1&&a[i]!=-1)printf("%d",a[i]);
		if(i==1)
		{
			printf("x");
			break;
		}
		printf("x^%d",i);
	}
	if(a[0]==0)
		return 0;
	if(a[0]>0)
		printf("+");
	printf("%d",a[0]);
	return 0;
} 

#include<cstdio>
using namespace std;
int a[10001],b[10001];
int main()
{
	int n,i,maxna=0,y=0;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
		if(a[i]>maxna) maxna=a[i];
	}
	
	for(i=1;i<=maxna;i++)
		if(b[i]>y) y=b[i];
		
	printf("%d",y);
	
}

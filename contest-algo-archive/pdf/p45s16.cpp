#include<cstdio>
using namespace std;
int a[20001];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(j=1;j<i;j++)
			if(a[i]==a[j]) a[i]=0; 
	}
	
	for(i=1;i<=n;i++)
		if(a[i]!=0) printf("%d ",a[i]);
		
	return 0;
}

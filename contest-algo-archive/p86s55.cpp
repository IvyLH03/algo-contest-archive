#include<cstdio>
using namespace std;
const int MAXN=10001;
int main()
{
	int a[MAXN];
	int maxa=0,n=1,k=1;
	while(~scanf("%d",&a[n]))
	{
		if(a[n]>maxa)
		{
			k=n;
			maxa=a[n];
		}
		n++;
	}
	printf("%d",k);
	return 0;
	
	
	
} 

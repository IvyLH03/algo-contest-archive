#include<cstdio>
using namespace std;
int main()
{
	int n,s=0,m;
	scanf("%d",&n);
	int a[n];
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i-1]);
	scanf("%d",&m);
	for(int i=0;i<=n-1;i++)
		if(a[i]==m)
			s++;
	printf("%d",s);
}

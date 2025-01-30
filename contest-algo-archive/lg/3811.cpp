#include<cstdio>
using namespace std;
int n,p;
long long inv[6000007];
int main()
{
	scanf("%d%d",&n,&p);
	inv[1]=1;
	int i;
	for(i=2;i<=n;i++)
	{
		inv[i]=(p-p/i)*inv[p%i]%p;
	}
	for(i=1;i<=n;i++)
		printf("%lld\n",inv[i]);
	return 0;
}

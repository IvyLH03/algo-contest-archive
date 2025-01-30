#include<cstdio>
#include<cmath>
using namespace std;
const int N=1000000;
bool istprime[N+7];
int prime[N+7],n,m,l,r,cnt[N+7];
void sprime()
{
	for(int i=2;i<=m;i++)
	{
		if(!istprime[i]) prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=m;j++)
		{
			istprime[prime[j]*i]=1;
			if(!(i%prime[j])) break;
		}
	}
	for(int i=2;i<=m;i++) cnt[i]=istprime[i]?cnt[i-1]:cnt[i-1]+1;
}
int main()
{
	scanf("%d%d",&n,&m);
	sprime();
	while(n--)
	{
		scanf("%d%d",&l,&r); 
		if(r>m||l<1) printf("Crossing the line\n");
		else printf("%d\n",cnt[r]-cnt[l-1]);
	}
	return 0;
}

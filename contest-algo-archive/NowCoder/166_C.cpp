#include<cstdio>
using namespace std;
long long n,k,c,cc,ans,i,cs;
int main()
{
	scanf("%lld%lld",&n,&k);
	c=n/(k+1);
	cc=c+(n-c*(k+1));	//printf("cc=%d,",cc);
	ans=c*cc;
	cs=c+cc;
	for(i=1;i<k;i++)
	{ 
		ans+=c*cs;
		cs+=c;
	}
	printf("%lld",ans);
	return 0;
}

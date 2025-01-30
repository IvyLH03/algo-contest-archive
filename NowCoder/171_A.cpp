#include<cstdio>
using namespace std;
long long a,b,c,op,ans;
int main()
{
	scanf("%lld%lld%lld%lld",&a,&op,&b,&c);
	if(op==1)
	{
		if(a>b) ans=0;
		else if(c<0) ans=-1;
			 else ans=(b-a)/c+1;
	}
	if(op==2)
	{
		if(a<b) ans=0;
		else if(c>0) ans=-1;
			 else ans=(b-a)/c+1;
	}
	if(op==3)
	{
		if(a==b) ans=0;
		else if(c==0||(a>b&&c>0)||(a<b&&c<0)) ans=-1;
			 else ans=(b-a)/c;
	}
	printf("%lld",ans);
	return 0;
} 

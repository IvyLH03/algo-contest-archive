#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long a1,b1,a0,b0,k1,k2,n;
long long gcd(long long a,long long b)
{
	while(b)
	{
		a%=b;swap(a,b);
	}
	return a;
}
int main()
{
	scanf("%d",&n);
	int iii;
	for(iii=1;iii<=n;iii++)
	{
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		long long k1=a0/a1,k2=b1/b0,i,cnt=0,s=sqrt(b1);
		for(i=1;i<=s;i++)
		{
			if(!(b1%i))
			{
				if((!(i%a1))&&gcd(k1,i/a1)==1&&gcd(b1/i,k2)==1) 	cnt++;
				if(i==b1/i) continue;
				if((!(b1/i%a1))&&gcd(k1,b1/i/a1)==1&&gcd(i,k2)==1) cnt++;
			}
		}
		
		printf("%lld\n",cnt);
	}
} 

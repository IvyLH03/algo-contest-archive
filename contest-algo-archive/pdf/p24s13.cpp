#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int k,i,m=1,n=1,o,aaa;
	scanf("%d",&k);
	aaa=ceil(1.0*(k-2)/3);
	for(i=1;i<=aaa;i+=1)
	{
		o=m+n;
		m=n+o;
		n=m+o;
		
	}
	if(k%3==0)
		printf("%d",o);
	if(k%3==1)
		printf("%d",m);
	if(k%3==2)
		printf("%d",n);
	
	return 0;
} 


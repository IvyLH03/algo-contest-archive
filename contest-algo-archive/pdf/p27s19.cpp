#include<cstdio>
using namespace std;
int main()
{
	int n,i,shu,a,b,c,d,r=0;
	scanf("%d",&n);
	for(i=1;i<=n;i+=1)
	{
		scanf("%d",&shu);
		a=shu/1000;
		b=((shu%1000)/100);
		c=(((shu%1000)%100)/10);
		d=(shu%10);
		if(d-a-b-c>0)
			r+=1;
	}
	printf("%d",r);
	
	return 0;
}

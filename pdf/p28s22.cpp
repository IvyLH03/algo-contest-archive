#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,r=0,i,n,empt,x;
	scanf("%d%d%d",&a,&b,&c);//a<b<c
	if(a>b)
	{
		empt=a;a=b;b=empt;
	}
	if(a>c)
	{
		empt=a;a=c;c=empt;
	}
	if(b>c)
	{
		empt=b;b=c;c=empt;
	}
	n=a;
	for(i=2;i<=n;i+=1)
	{
		if(((a%i)==(b%i))&&((a%i)==(c%i)))
			{
				if(r==0)
					r=i;
					x=r;
			}
		 
	}
	printf("%d",x);
	return 0;
}

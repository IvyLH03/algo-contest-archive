#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,n,i,empt;
	scanf("%d%d%d",&n,&a,&c);
	if(a<c)
	{
		empt=a;a=c;c=empt;
	}
	for(i=3;i<=n;i+=1)
	{
		scanf("%d",&b);
		if(b>a) a=b;
		if(b<c) c=b;
		
	}
	printf("%d",a-c);
	return 0;
}

#include<cstdio>
using namespace std;
int main()//¼¦Î²¾ÆÁÆ·¨ 
{
	int x,i,c1,c2,n1,n2;
	float c,n;
	scanf("%d",&x);
	scanf("%d%d",&c1,&c2);
	c=1.0*c1/c2;
	for(i=1;i<=(x-1);i+=1)
	{
		scanf("%d%d",&n1,&n2);
		n=1.0*n1/n2;
		if((n-c)>=0.05)
			printf("worse\n");
		if((c-n)>=0.05)
			printf("better\n");
		if((c-n)<=0.05&&(n-c)<=0.05)
			printf("same\n"); 
	}

	return 0;
} 

#include<cstdio>
using namespace std;
int main()
{
	char c;
	int a,b,ifn,i,j;
	scanf("%d%d %c%d",&a,&b,&c,&ifn);
	for(i=1;i<=b;i+=1)
	{
		printf("%c",c);
	}
	printf("\n");
	for(j=3;j<=a;j+=1)
	{
		if(ifn==1)
		{
			for(i=1;i<=b;i+=1)
			{
				printf("%c",c);
			} 
			printf("\n");
		}
		if(ifn==0)
		{
			printf("%c",c);
			for(i=3;i<=b;i+=1)
			{
				printf(" ");
			}
			printf("%c\n",c);
		}
	}
	for(i=1;i<=b;i+=1)
	{
		printf("%c",c);
	}
	return 0;
}

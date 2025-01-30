#include<cstdio>
using namespace std;
int main()
{
	char c;
	int gao,kuan,i,k,shi;
	scanf("%d%d %c%d",&gao,&kuan,&c,&shi);
	for(i=1;i<=kuan;i++)
		printf("%c",c);
	printf("\n");
	for(i=3;i<=gao;i++)
	{
		if(shi==1)
		{
			for(k=1;k<=kuan;k++)
			{
				printf("%c",c);
			}
		}
		if(shi==0)
		{
			printf("%c",c);
			for(k=3;k<=kuan;k++)
				printf(" ");
			printf("%c",c);
		} 
		printf("\n");
	}
	for(i=1;i<=kuan;i++)
		printf("%c",c);
	return 0;
}

#include<cstdio>
using namespace std;
int main()
{	//3,5,7ÊÇ·ñ³ý¿ª 
	int a;
	scanf("%d",&a);
	if(a%3==0)
		printf("3 ");
	if(a%5==0)
		printf("5 ");
	if(a%7==0)
		printf("7 ");
	if(a%3!=0&&a%5!=0)
	{
		if(a%7!=0)
		printf("n");
	}
	return 0;	
}

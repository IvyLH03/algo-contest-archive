#include<cstdio>
using namespace std;
int main()
{
	float a,b;
	char c;
	scanf("%f%c%f",&a,&c,&b);
	switch(c)
	{
		case '+':printf("%f",a+b);break;
		case '-':printf("%f",a-b);break;
		case '*':printf("%f",a*b);break;
		case '/':
					if(c!=0) 
					{
						printf("%f",a/b);break;
					}
				 	else
				 	{
				 		printf("Divided by zero!");break;
				 	}
		default:printf("Invalid operator!");
		
	}
	return 0;
}

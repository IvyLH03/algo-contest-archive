#include<cstdio>
using namespace std;
int main()
{
	int a,b,c;
	char ch;
	scanf("%d%d%c",&a,&b,&ch);
	if(ch='+')
		c=a+b;
	else 
	{
	if(ch='-')
			c=a-b;
		 else 
		 {
		 	if(ch='*')
				c=a*b;
			  else 
			  {
			   if(ch='/')
			  		if(b=0)
			  			printf("Divided by zero!");
			  		else
			  			c=a/b;
			  
			  	   else
			  	   	printf("£ºInvalid operator!");
				}
		}
	}
	printf("%d",c);
		 
	return 0;
}

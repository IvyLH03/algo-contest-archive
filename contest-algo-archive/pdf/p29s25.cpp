#include<cstdio>
using namespace std;
int main()
{	
	int a,b,n,i,x;
	scanf("%d%d",&a,&b);
	for(i=1;i<=b;i+=1)
	{
		x=a*a%7;
	}
	switch(x)
	{
		case 1:printf("Monday");break;
		case 2:printf("Tuesday");break;
		case 3:printf("Wednesday");break;
		case 4:printf("Thursday");break;
		case 5:printf("Friday");break;
		case 6:printf("Saturday");break;
		case 0:printf("Sunday");break;
	}
	return 0;
}

#include<cstdio>
using namespace std;
void jia(int a,int b)
{
	printf("%d",a+b);
}
void jian(int a,int b)
{
	printf("%d",a-b);
}
void cheng(int a,int b)
{
	printf("%d",a*b);
}
void chu(int a,int b)
{
	printf("%d",a/b);
}
int main()
{
	int a,b;
	char ch;
	scanf("%d%c%d",&a,&ch,&b);
	if(ch=='+')jia(a,b);
	if(ch=='-')jian(a,b);
	if(ch=='*')cheng(a,b);
	if(ch=='/')chu(a,b);
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;
int stack[101];
char s[256];
int main()
{
	gets(s);
	int i=0,top=0,x,y;
	while(i<=strlen(s)-2)
	{
		switch(s[i])
		{
			case'+':stack[--top]+=stack[top+1];break;
			case'-':stack[--top]-=stack[top+1];break;
			case'*':stack[--top]*=stack[top+1];break;
			case'/':stack[--top]*=stack[top+1];break;
			default:x=0;while(s[i]!=' ')x=x*10+s[i++]-'0';
				stack[++top]=x;break;
		}
		i++;
	}
	
	
	printf("%d",stack[top]);
	return 0;
}

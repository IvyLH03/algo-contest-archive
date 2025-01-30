#include<cstdio>
using namespace std;
char s[256];
int main()
{
	int i=0,top=0;
	gets(s);
	while(s[i]!='@')
	{
		if(s[i]=='(')top++;
		if(s[i]==')')top--;
		i++;
	}
	if(top==0)printf("YES");
	else printf("NO");
	return 0;
}

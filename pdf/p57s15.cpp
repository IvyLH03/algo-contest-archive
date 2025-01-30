#include<cstdio>
#include<cstring>
using namespace std;
char s[33],y[33];
int main()
{
	gets(s);
	if((s[strlen(s)-1]=='r'&&s[strlen(s)-2]=='e')||(s[strlen(s)-1]=='y'&&s[strlen(s)-2]=='l'))strncpy(y,s,strlen(s)-2);
	if(s[strlen(s)-1]=='g'&&s[strlen(s)-2]=='n'&&s[strlen(s)-3]=='i')strncpy(y,s,strlen(s)-3);
	puts(y);
	return 0;
}

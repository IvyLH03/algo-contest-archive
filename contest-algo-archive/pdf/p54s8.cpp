#include<cstdio>
#include<cstring>
using namespace std;
char s[80],n[80];
int main()
{
	int i;
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		n[i]=s[i];
		if(s[i]>='a'&&s[i]<'z')n[i]=s[i]+1;
		if(s[i]>='A'&&s[i]<'Z')n[i]=s[i]+1;
		if(s[i]=='z')n[i]='a';
		if(s[i]=='Z')n[i]='A';
		
		
	}
	puts(n);
	return 0;
}

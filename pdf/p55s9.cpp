#include<cstdio>
#include<cstring>
using namespace std;
char s[51],y[51],h[51];
int main()
{
	int i,k=0;
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>='a'&&s[i]<='w')y[i]=s[i]-29;
		if(s[i]>='A'&&s[i]<='W')y[i]=s[i]+35;
		if(s[i]=='x')y[i]='A';
		if(s[i]=='y')y[i]='B';
		if(s[i]=='z')y[i]='C';
		if(s[i]=='X')y[i]='a';
		if(s[i]=='Y')y[i]='b';
		if(s[i]=='Z')y[i]='c';
		
	}
	for(i=strlen(y)-1;i>=0;i--)
		h[k++]=y[i];
	puts(h);
	return 0;
}

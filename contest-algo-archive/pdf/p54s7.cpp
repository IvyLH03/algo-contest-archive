#include<cstdio>
#include<cstring>
using namespace std;
char st[256],y[256];
int main()    // A¡¢T¡¢G¡¢C
{
	gets(st);
	for(int i=0;i<strlen(st);i++)
	{
		if(st[i]=='A')y[i]='T';
		if(st[i]=='T')y[i]='A';
		if(st[i]=='G')y[i]='C';
		if(st[i]=='C')y[i]='G';
	}
	puts(y);
	return 0;
}

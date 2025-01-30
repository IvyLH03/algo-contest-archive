#include<cstdio>
#include<cstring>
using namespace std;
char s[201],y[201];
int main()
{
	gets(s);
	int k=0,i;
	for(i=0;i<strlen(s);i++)
		if(!(s[i]==' '&&s[i-1]==' '))y[k++]=s[i];
	puts(y);
	return 0;
}

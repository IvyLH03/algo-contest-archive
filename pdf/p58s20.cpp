#include<cstdio>
#include<cstring>
using namespace std;
char s[1001];
int main()
{
	int i,p=1;
	gets(s);
	for(i=0;i<strlen(s);i++)
	{
		while(s[i+1]==s[i])
		{
			p++;i++;
		}
		printf("%d%c",p,s[i]);
		p=1;
	}
	return 0;
} 

#include<cstdio>
#include<cstring>
using namespace std;
char s[101],y[101];
int main()
{
	int i=0,n=0;
	gets(s);
	while(s[i]==s[strlen(s)-1-i])
	{
		i++;n++;
	}
	if(n=strlen(s)/2)printf("yes");
	else printf("no");
	return 0;
}

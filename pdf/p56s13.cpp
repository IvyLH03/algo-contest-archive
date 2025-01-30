#include<cstdio>
#include<cstring>
using namespace std;
char s1[80],s2[80];
int main()
{
	gets(s1);gets(s2);
	strupr(s1);strupr(s2);
	int y=strcmp(s1,s2);
	if(y==0)printf("=\n");
	if(y<0)printf("<\n");
	if(y>0)printf(">\n");
	return 0;
}

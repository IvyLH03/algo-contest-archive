#include<cstdio>
#include<cstring>
using namespace std;
char s1[201],s2[201];
int main()
{
	scanf("%s%s",s1,s2);
	if(strstr(s1,s2)!=NULL)printf("%s is substring of %s",s2,s1);
	else if(strstr(s2,s1)!=NULL)printf("%s is substring of %s",s1,s2);
		else printf("No substring");
	return 0;
}

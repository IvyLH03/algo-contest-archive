#include<cstdio>
#include<cstring>
using namespace std;
char s[256];
int num1;
bool flag;
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(') num1++;
		if(s[i]==')') num1--;
		if(num1<0)
		{
			flag=1;break;
		}
	}
	if(flag||num1) printf("NO");
	else printf("YES");
	return 0;
}

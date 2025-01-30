#include<cstdio>
#include<cstring>
using namespace std;
char st[21];
int main()
{
	int y=1,i;//y=trueʱ,yes.
	gets(st);
	if(!(st[0]>='1'&&st[0]<='0'))
	{
		for(i=0;i<strlen(st);i++)
			if(!((st[i]>='a'&&st[i]<='z')||(st[i]>='A'&&st[i]<='Z')||(st[i]=='_')))y=0;	
	}
	else y=0;
	if(y==0)printf("no");
	else printf("yes");
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;
char st[100001];
int s[100001];
int main()
{
	gets(st);
	int i,y=0;	char j;
	for(i=0;i<=strlen(st);i++)
	{
		s[st[i]]++;
	}
	for(j='a';j<='z';j++)
	{
		//printf("%d ",s[j]);
		if(s[j]==1)
		{
			printf("%c",j);
			y++;
			break;
		}
	}
	if(y==0) printf("no");
	return 0;
}

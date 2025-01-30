#include<cstdio>
using namespace std;
char s[10001];
void dxxc(char s[],int i)
{
	if(s[i]!='!')
	{
		dxxc(s,i+1);
		printf("%c",s[i]);
	}
	else return;
}
int main()
{
	scanf("%s",s);
	dxxc(s,0);
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;
char s[101][21];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		if(s[i][0]>='a'&&s[i][0]<='z')s[i][1]+=32;
		for(j=1;j<strlen(s[i]);j++)
			if(s[i][j]>='A'&&s[i][j]<='Z')s[i][j]+=32;
	}
	for(i=1;i<=n;i++)
		puts(s[i]);
	return 0;

}

#include<cstdio>
#include<cstring>
using namespace std;
char s[501][501],y[501][501];
int main()
{
	int i,k,j,u=0;
	while(scanf("%s",s[i++])==1);
	for(k=0;k<i-1;k++)
	{
		for(j=strlen(s[k])-1;j>=0;j--)
			printf("%c",s[k][j]);
		printf(" ");
	}
	return 0;
}

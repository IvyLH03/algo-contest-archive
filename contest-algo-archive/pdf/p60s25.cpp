#include<cstdio>
#include<cstring>
using namespace std;
char s[501][501];
int main()
{
	int i=0,maxn=0,sit,k;
	while((scanf("%s",s[i++]))==1);
	s[i-2][strlen(s[i-2])-1]='\0';

	for(k=0;k<i;k++)
	{
		
		if(strlen(s[k])>maxn)
		{
			maxn=strlen(s[k]);sit=k;
		}
	}
	printf("%s",s[sit]);
	return 0;
} 

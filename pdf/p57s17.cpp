#include<cstdio>
#include<cstring>
using namespace std;
char s[301][301];
int main()
{
	int i=0,k,sl=0;
	while((scanf("%s",s[i++]))==1);
	for(k=0;k<i-1;k++)
		{
			if(sl!=0) printf(",%d",strlen(s[k]));
			else printf("%d",strlen(s[k]));
			sl++;
		}
	return 0;
}

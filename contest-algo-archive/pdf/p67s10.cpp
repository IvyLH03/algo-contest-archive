#include<cstdio>
#include<cstring> 
using namespace std;
char jz[101][101],yc[101],th[101];
int main()
{
	int i=0;
	while(scanf("%s",jz[i++])==1);
	scanf("%s%s",yc,th);
	for(int j=0;j<i;j++)
	{
		if(strcmp(jz[j],yc)==0)strcpy(jz[j],th);
		printf("%s ",jz[j]);
	}
	return 0;
	
}

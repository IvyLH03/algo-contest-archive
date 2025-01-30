#include<cstdio>
#include<cstring>
using namespace std;
char K[101],C[1001];
void py(char &zm,char k[],int &i)
{
	int s=i%strlen(K);
	if(((zm<='z'&&zm>='a')&&(zm-k[s]<'a'))||((zm<='Z'&&zm>='A')||(zm-k[s]<'A')))  
	{
		if(zm<='z'&&zm>='a')zm='z'-k[i]+zm;
		if(zm<='Z'&&zm>='A')zm='Z'-k[i]+zm;
	}
	else zm-=k[s];
}

int main()
{
	int s;
	scanf("%s%s",K,C);
	strupr(K);
		//puts(K);
	for(int i=0;i<strlen(K);i++)
		K[i]-='A';

		//for(int i=0;i<strlen(K);i++)
		//	printf("%d ",K[i]);
		//printf("\n");
		
	for(int i=0;i<strlen(C);i++)
	{
		py(C[i],K,i);
		printf("%c",C[i]);
	}
	return 0;
}


#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char t[21],cname[11][21];
	for(int i=1;i<=10;i++) scanf("%s",cname[i]);
	for(int i=1;i<=9;i++)
	{
		int k=i;
		for(int j=i;j<=10;j++)
			if(strcmp(cname[k],cname[j])>0) k=j;
		strcpy(t,cname[i]);strcpy(cname[i],cname[k]);strcpy(cname[k],t);	
	}
	for(int i=1;i<=10;i++)
		printf("%s\n",cname[i]);
	return 0;
}

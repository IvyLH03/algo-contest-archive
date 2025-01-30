#include<cstdio>
#include<cstring>
using namespace std;
char a1[101];
int a[101],c[101];
int main()
{
	gets(a1);
	int lena=strlen(a1),i,x=0;
	for(i=0;i<lena;i++)
		a[i+1]=a1[i]-'0';
	for(i=1;i<=lena;i++)
	{
		c[i]=(x*10+a[i])/13;
		x=(x*10+a[i])%13;
	} 
	int st=1;
	while(c[st]==0&&lena-st>1)st++;
	for(i=st;i<=lena;i++)printf("%d",c[i]);
	printf("\n%d",x);
	return 0;
} 

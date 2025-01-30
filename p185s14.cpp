#include<cstdio>
#include<cstring>
using namespace std;
char a1[100];
int a[100],c[100],lena,i,x,lenc,b;
int main()
{
	scanf("%s%d",a1,&b);
	lena=strlen(a1);
	for(i=0;i<=lena-1;i++)
		a[i+1]=a1[i]-48;
	for(i=1;i<=lena;i++)
	{
		c[i]=(x*10+a[i])/b;
		x=(x*10+a[i])%b;
	}
	lenc=1;
	while(c[lenc]==0&&lenc<lena)
		lenc++;
	for(i=lenc;i<=lena;i++)
		printf("%d",c[i]);
	return 0;
} 

#include<cstdio>
#include<cstring>
using namespace std;
char a1[31];
int a[31],c[31];
int main()
{
	gets(a1);
	int lena=strlen(a1),x=0,r=0,i;
	for(int i=0;i<lena;i++)
		a[i+1]=a1[i]-'0';
	for(i=2;i<=9;i++)
	{
		x=0;
		for(int j=1;j<=lena;j++)
		{
			c[j]=(x*10+a[j])/i;
			x=(x*10+a[j])%i;
		}
				//	printf("%d:%d\n",i,c[i]);
		if(x==0)
		{
			if(r==0)printf("%d",i);
			else printf(" %d",i);
			r++; 
		}
	}
	if(r==0)printf("none");
	return 0;
}

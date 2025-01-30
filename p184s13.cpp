#include<cstdio>
#include<cstring>
char a1[256],b1[256];
int a[256],b[256],c[256];
int main()
{
	gets(a1);gets(b1);
	int lena=strlen(a1),lenb=strlen(b1);
	int x,i;
	for(i=0;i<lena;i++)a[lena-i]=a1[i]-'0';
	for(i=0;i<lenb;i++)b[lenb-i]=b1[i]-'0';
	for(i=1;i<=lena;i++)
	{
		x=0;
		for(int j=1;j<=lenb;j++)
		{
			c[i+j-1]=a[i]*b[j]+x+c[i+j-1];
			x=c[i+j-1]/10;
			c[i+j-1]%=10;	
		}
		c[i+lenb]=x;
	}
	int lenc=lena+lenb;
	while(c[lenc]==0&&lenc>1)
		lenc--;
	for(i=lenc;i>0;i--)
		printf("%d",c[i]);
	printf("\n");
	return 0;
}

#include<cstdio>
#include<cstring>
char a[1025][2049];
int n;
int main()
{
	memset(a,' ',sizeof(a));
	scanf("%d",&n);
	a[1][1]=a[2][2]='/';
	a[1][2]=a[1][3]='_';
	a[1][4]=a[2][3]='\\'; 
	int hig=1,len=2,i,j,k;
	for(k=1;k<=n;k++)
	{
		len*=2;hig*=2;
		for(i=1;i<=hig;i++)
		{
			for(j=1;j<=len;j++)
			{
				a[i][j+len]=a[i+hig][j+len/2]=a[i][j];
			}
		}
	} 
	for(i=hig;i>=1;i--)
	{
		for(j=1;j<=len;j++)
			printf("%c",a[i][j]);
		printf("\n");
	}
	return 0;
			
		
}

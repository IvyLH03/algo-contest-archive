#include<cstdio>
#include<cstring>
using namespace std;
int c[100001],ls[100001];
int main()
{
	int a,x=0,lenls,j,i,k;
	scanf("%d",&a);
	c[1]=1;
	for(i=2;i<=a;i++)
	{
		memset(ls,0,sizeof(ls));
		ls[1]=1;lenls=1;
		for(j=2;j<=i;j++);
		{
			x=0;
			for(k=1;k<=lenls;k++)
			{
				ls[k]=x+ls[k]*j;
				x=ls[k]/10;
				ls[k]%=10;
printf("i:%d j:%d k:%d x=%d ls[%d]=%d\n",i,j,k,x,k,ls[k]); 
			}
			while(x)
			{
				ls[++lenls]=x%10;
				x/=10;
			}
							printf("lenls:%d\n",lenls);
		}
					printf("i:%d  ls:",i);
					for(j=lenls;j>=1;j--);
						printf("%d",ls[j]);
					printf("\n\n");
		for(j=1;j<=lenls;j++)
			c[j]+=ls[j];
		
	}
	for(i=lenls;i>=1;i--)
		printf("%d",c[i]);
	return 0;
}

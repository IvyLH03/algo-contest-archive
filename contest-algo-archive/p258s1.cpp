#include<cstdio>
#include<cmath>
using namespace std;
int a[9];
bool b[9],c[16],d[16];
int tot=0;
int search(int);
int print();
int main()
{
	search(1);
	return 0;
}
int search(int t)
{
	int i;
	for(i=1;i<=8;i++)
	{
		if((!b[i])&&(!c[i+t])&&(!d[i-t+7]))
		{
			a[t]=i;b[i]=1;c[i+t]=1;d[i-t+7]=1;
			if(t==8)print();
			else search(t+1);
			a[t]=0;b[i]=0;c[i+t]=0;d[i-t+7]=0;
		}
	}
}
int print()
{
	int i,j;
	tot++;
	printf("No. %d\n",tot);
	for(i=1;i<=8;i++)
	{
		for(j=1;j<=8;j++)
		{
			if(a[i]==j)printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}

#include<cstdio>
using namespace std;
bool b[9]={0},c[16]={0},d[16]={0};
int a[9],sum;
void print();
void search(int i)
{
	int j;
	for(j=1;j<=8;j++)
	{
		if((!b[j])&&(!c[i+j])&&(!d[i-j+7]))
		{
			a[i]=j;
			b[j]=1;c[i+j]=1;d[i-j+7]=1;
			if(i==8)print();
			else search(i+1);
			b[j]=0;c[i+j]=0;d[i-j+7]=0;
		}
	}
}
void print()
{
	int i,j;
	printf("No.%d\n",++sum);
	for(i=1;i<=8;i++)
	{
		for(j=1;j<=7;j++)
		{
			if(a[i]==j)printf("1 ");
			else printf("0 ");
		}
		if(a[i]==j)printf("1\n");
		else printf("0\n");
	}
	
}
int main()
{
	search(1);
	return 0;
}


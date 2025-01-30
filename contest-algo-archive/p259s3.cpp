#include<cstdio>
using namespace std;
int a[93][9],dt[93],total,ls[9];
bool b[9],c[15],d[15];
int search(int);
int print();
int main()
{
	search(1);
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&dt[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=8;j++)
			printf("%d",a[dt[i]][j]);
		printf("\n");
	}
	//			printf("-------\n");
	//			for(i=1;i<=92;i++)
	//			{
	//				printf("%d: ",i);
	//				for(j=1;j<=8;j++)
	//				{
	//					printf("%d",a[i][j]);
	//				}
	//				printf("\n");
	//			}
				
	return 0;
}
int search(int t)
{
	int i;
	for(i=1;i<=8;i++)
	{
		if((!b[i])&&(!c[i+t])&&(!d[i-t+7]))
		{
			ls[t]=i;b[i]=1;c[i+t]=1;d[i-t+7]=1;
			if(t==8)print();
			else search(t+1);
			ls[t]=0;b[i]=0;c[i+t]=0;d[i-t+7]=0;
		}
	}
}
int print()
{
	total++;
	int i;
	for(i=1;i<=8;i++)
		a[total][i]=ls[i];
}

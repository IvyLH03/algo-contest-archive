#include<cstdio>
using namespace std;
int a[11];
int main()
{
	int i,j,temp;
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=9;i++)
		for(j=1;j<=10-i;j++)
			if(a[j]<a[j+1])
				{
					temp=a[j];a[j]=a[j+1];a[j+1]=temp;
				}
	for(i=1;i<=9;i++)
		printf("%d ",a[i]); 
	printf("%d",a[10]);
	return 0;
}

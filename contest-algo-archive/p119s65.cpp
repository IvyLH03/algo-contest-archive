#include<cstdio>
using namespace std;
void bubble(int[],int);
int main()
{
	int i;
	int array[10]={11,2,55,6,77,8,9,0,7,1};
	printf("≈≈–Ú«∞ ");
	for(i=0;i<9;i++)printf("%d,",array[i]);
	printf("%d\n",array[9]);
	bubble(array,10);
	printf("≈≈–Ú∫Û "); 
	for(i=1;i<9;i++)printf("%d,",array[i]);
	printf("%d",array);
	return 0; 
}
void bubble(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(a[j]>a[j+1])
		{
			temp=a[j];a[j]=a[j+1];a[j+1]=temp;
		}
	}
} 

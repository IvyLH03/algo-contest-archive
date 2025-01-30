#include<cstdio>
using namespace std;
int dx[4]={1,-1,2,-2}, 
	dy[4]={2,2,1,1},
	a[100][3],t=0;
int print(int);
int search(int i)
{
	int j;
	for(j=0;j<=3;j++)
		if(a[i-1][1]+dx[j]>=0&&a[i-1][1]+dx[j]<=4
			&&a[i-1][2]+dy[j]>=0&&a[i-1][2]+dy[j]<=8)
		{
			a[i][1]=a[i-1][1]+dx[j];
			a[i][2]=a[i-1][2]+dy[j];
			if(a[i][1]==4&&a[i][2]==8)print(i);
			else search(i+1); 
		}
}
int print(int ii)
{
	t++;
	printf("%d: ",t);
	for(int i=1;i<=ii-1;i++)
		printf("%d,%d->",a[i][1],a[i][2]);
	printf("4.8\n");
}
int main()
{
	a[1][1]=0;a[1][2]=0;
	search(2); 
	return 0;
}

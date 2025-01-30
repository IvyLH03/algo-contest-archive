#include<cstdio>
using namespace std;
int dx[8]={2,2,1,1,-1,-1,-2,-2},
	dy[8]={1,-1,2,-2,2,-2,1,-1};
int a[100][100],num;
bool b[100][100];
int search(int,int,int);
int print();
int main()
{
	a[1][1]=1;b[1][1]=1;
	search(1,1,2);
	printf("%d",num);
	return 0;
} 
int search(int m,int n,int t)
{
	if(t>25){
		print();return 0;  
	}
	int i,x,y;
	for(i=0;i<=7;i++)
	{
		x=m+dx[i];y=n+dy[i];
		if(x<=5&&y<=5&&x>=1&&y>=1&&(!b[x][y]))
		{
			b[x][y]=1;
			a[x][y]=t;
			search(x,y,t+1);
			b[x][y]=0;a[x][y]=0;
		}
	}
}
int print()
{
	int i,j;
	if(++num<=5)
	{
		for(i=1;i<=5;i++)
		{
			for(j=1;j<=5;j++)
				printf("%5d",a[i][j]);
			printf("\n");
		}printf("\n");
	}
	
}

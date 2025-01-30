#include<cstdio>
using namespace std;
int book[6],c;
bool flag[6],like[6][6]={{0,0,0,0,0,0},{0,0,0,1,1,0},{0,1,1,0,0,1},{0,0,1,1,0,0},{0,0,0,0,1,0},{0,0,1,0,0,1}};
int search(int);
int print();
int main()
{
	for(int i=1;i<=5;i++)flag[i]=1;
	search(1);
	return 0;                        
}
int search(int i)
{
	int j;
	for(j=1;j<=5;j++)
	if(flag[j]&&like[i][j])
	{
		flag[j]=0;
		book[i]=j;
		if(i==5)print();
		else search(i+1);
		flag[j]=1;book[i]=0;
	}
}
int print()
{
	c++;
	printf("answer %d:\n",c);
	for(int i=1;i<=5;i++)
		printf("%d:%c\n",i,64+book[i]);
}

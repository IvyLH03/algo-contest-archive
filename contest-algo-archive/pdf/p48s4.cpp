#include<cstdio>
using namespace std;
int a[6][6];
int main()
{
	int i,j,li,maxn=0,s=0;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
			scanf("%d",&a[i][j]);
	}
	
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
			if(a[i][j]>maxn)
			{
				maxn=a[i][j];
				li=j;
			}
			
		for(j=1;j<=5;j++)
			if(a[j][li]>maxn) s++;
			
		if(s==4)
		{
			printf("%d %d %d",i,li,maxn);
			break;
		}
		s=maxn=0;
	}
	if(s=0) printf("not found");
	return 0;		
}

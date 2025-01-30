#include<cstdio>
using namespace std;
int a[110];
int main()
{
	int i,k,n,first=1;
	for(i=1;i<=100;i++)
		for(k=1;k<=100;k++)
			if(k%i==0)
				a[k]=!a[k];	
		
	for(i=1;i<=100;i++)
	{
		if(a[i]==1)
		{
			if(first==1)
				first=0;
			else
				printf(" ");
			printf("%d",i);
		}
			
	}

	return 0;
}

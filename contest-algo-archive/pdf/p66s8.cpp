#include<cstdio>
using namespace std;
int jss(int i)
{
	int s=0;
	for(int k=1;k<=i;k++)
	{
		s+=k; 
	}
	return s;
}
int main()
{
	int n,s,r=0;
	scanf("%d",&n);
	for(int i=1;i<100000;i++)
	{
		s=jss(i);
		for(int j=1;j<=i;j++)
		{
			if(s-2*j==n)
			{
				printf("%d %d",j,i);
				r++;break;
			}
		}
		if(r==1)break;
	}
	return 0;
}

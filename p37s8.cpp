#include<cstdio>
using namespace std;
int main()
{
	int n,i=2,maxn=0;
	scanf("%d",&n);
	do
	{
		while(n%i==0)
		{
			n/=i;
			if(i>maxn)
				maxn=i;
		}
		i++;
	}
	while(n!=1);
	printf("%d",maxn);
	return 0;
}


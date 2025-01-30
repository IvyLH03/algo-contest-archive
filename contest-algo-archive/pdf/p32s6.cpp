#include<cstdio>
using namespace std;
int main()
{
	int m,k,x,k2=0;
	scanf("%d%d",&m,&k);
	if(m%19==0)
	{
		while(m!=0)
		{
			x=m%10;
			if(x==3)
				k2+=1;
			m=(m-x)/10;
		}
		if(k2==k)
			printf("YES");
		else
			printf("NO");
	}
	else
		printf("NO");
}

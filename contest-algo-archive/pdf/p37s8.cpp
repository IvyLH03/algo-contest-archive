#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,s1=1,s2,y,cin=0;
	scanf("%d",&n);
	while(cin!=1)
	{
		s1++;
		if(n%s1==0)
		{
			s2=n/s1;
			cin=1;
		}
	}
	y=s1>s2? s1:s2;
	printf("%d",y);
	return 0;
}

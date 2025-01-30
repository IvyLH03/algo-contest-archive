#include<cstdio>
using namespace std;
int main()
{
	int s=0,n=0;
	while(s<1000)
	{
		n++;
		s+=n;
	}
	printf("%d",n);
	return 0;
}

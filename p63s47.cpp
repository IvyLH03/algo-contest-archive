#include<cstdio>
using namespace std;
int main()
{
	int n=0;
	float s=0;
	while(s<5)
	{
		n+=1;
		s+=1.0/n;
	}
	printf("%d",n);
	return 0;
}

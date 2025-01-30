#include<cstdio>
using namespace std;

int main()
{
	int x=7,y=8;
	int z1=y-(x++);
	int z2=y-(++x);
	printf("z1=%d\nz2=%d",z1,z2);
	return 0; 
	
}

#include<cstdio>
using namespace std;
int main()
{
	int x,y,z;
	for(x=0;x<=100/5;x++)
	{
		for(y=0;y<=100/3;y++)
		{
			z=100-x-y;
			if(x+y+z==100&&x*5+y*3+z/3==100&&z%3==0)
				printf("%d %d %d\n",x,y,z); 
		}
	}
	return 0;
}

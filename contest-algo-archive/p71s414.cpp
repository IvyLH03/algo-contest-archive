#include<cstdio>
using namespace std;
int main()
{
	int x,y,z;
	for(x=0;x<=100/5;x+=1)
		for(y=0;y<=100/3;y+=1)
			for(z=0;z<=100*3;z+=1)
				if((x+y+z==100)&&(5*x+3*y+z/3==100)&&(z%3==0))
					printf("%d %d %d\n",x,y,z);
	return 0;
}

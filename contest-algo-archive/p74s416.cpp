#include<cstdio>
#include<cmath>
using namespace std;
int main()
{	
	int i,x;
	for(i=100;i<=200;i+=1)
	{
		x=2;
		while((x<=floor(sqrt(i)))&&(i%x!=0))
			x++;
		if(x>(floor(sqrt(i))))
			printf("%d ",i); 
	}
	
	return 0;
}

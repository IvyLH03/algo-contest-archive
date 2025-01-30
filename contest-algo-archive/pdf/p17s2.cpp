#include<cstdio>
using namespace std;
int main()
{
	int S;
	double a,b;
	scanf("%d",&S);
	a=27+23+S/3.0;
	b=S/1.2;
	if(a<b)
    	printf("Bike");
    else if(a=b)
    		printf("All");
    	 else
    	 	printf("Walk");
	return 0;
}

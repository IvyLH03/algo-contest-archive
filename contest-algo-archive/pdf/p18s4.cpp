#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	char ch;
	scanf("%d %c",&a,&ch);
	if(a<=1000)
		b=8;
	else
		if((a-1000)%500==0)
			b=8+(a-1000)/500*4;
		else
			b=8+((a-1000)/500+1)*4;
	if(ch='y')
		b=b+5;
	printf("%d",b);
	return 0; 
}

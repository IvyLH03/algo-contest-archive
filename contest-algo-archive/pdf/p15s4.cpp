#include<cstdio>
using namespace std;
int main()
{
	char a;
	scanf("%c",&a);
	if(a%2==1)  //char可以直接计算ASCII值 
		printf("yes");
	else
		printf("no");
	return 0;
}

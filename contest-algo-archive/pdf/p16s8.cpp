#include<cstdio>
using namespace std;
int main()
{
	int a;
	scanf("%d",&a);
	if(a%3==0&&a%5==0)
		printf("YES");
	else
		printf("NO");
	return 0;	
}

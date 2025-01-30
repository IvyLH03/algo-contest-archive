#include<cstdio>
using namespace std;
int h(int x)
{
	if(x==1)return 1;
	else return x+h(x-1);
}
int  main()
{
	int n;
	scanf("%d",&n);
	printf("%d",h(n));
	return 0;
}

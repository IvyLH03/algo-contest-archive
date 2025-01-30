#include<cstdio>
#include<cmath>
using namespace std;
int pd(int x);
int main()
{
	int n;
	scanf("%d",&n);
	printf("2");
	for(int i=3;i<=n;i++)
		if(pd(i)==1)printf(",%d",i);
	return 0;
}
int pd(int x)
{
	int i=2;
	while(x%i!=0&&i<=sqrt(x))i++;
	if(x%i!=0)return 1;
	else return 0;
}

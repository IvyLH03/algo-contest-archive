#include<cstdio>
using namespace std;
int i;
int digit(int x,int k)
{
	if(k==1)return x%10;
	else 
	{
		return digit(x/10,k-1);
	}
}
int main()
{
	int x,k;
	scanf("%d%d",&x,&k);
	printf("%d",digit(x,k));
	return 0; 
}

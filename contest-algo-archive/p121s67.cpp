#include<cstdio>
#include<cmath>
using namespace std;
int prime(int x)
{
	int j;
	if(x==2)return 1;
	j=2;
	while(j<=sqrt(x)&&x%j!=0)j++;
	if(x%j==0) return 1;
	else return 0;
} 

int main()
{
	int x;
	scanf("%d",&x);
	if(prime(x)==0)printf("%s\n","yes");
	else printf("%s\n","no");
	return 0;
} 

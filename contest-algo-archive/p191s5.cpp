#include<cstdio>
using namespace std;
int c[100001];
int main()
{
	int a;
	scanf("%d",&a);															//Cai,Xue-Yu. 
	int x=0,lenc=1;
	c[1]=1;
	for(int i=2;i<=a;i++)
	{
		x=0;
		for(int j=1;j<=lenc;j++)
		{
			c[j]=x+c[j]*i;
			x=c[j]/10;
			c[j]%=10;
		}
		while(x)
		{
			c[++lenc]=x%10;
			x/=10;
		}
		
	}
	while(c[lenc]==0&&lenc>1)lenc--;
	for(int i=lenc;i>=1;i--)
		printf("%d",c[i]);
	return 0;
}

#include<cstdio>
using namespace std;
const int size=100;
int a[size+1],n,d,i=0,j;
int main()
{
	scanf("%d%d",&n,&d);
	do
	{
		a[++i]=n%d;
		n=n/d;
	}	 
	while(n!=0);
	for(j=i;j>=1;j--)printf("%d",a[j]);
	return 0;
	
}









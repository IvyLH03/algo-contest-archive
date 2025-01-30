#include<cstdio>
#include<cmath>
using namespace std;
const int n=100;
bool a[n+1];
int main()
{
	int i,j,t=0;
	for(i=2;i<=n;i++)a[i]=true;
	
	for(i=2;i<=sqrt(n);i++)
		if(a[i])
			for(j=2;j<=n/i;j++)
				a[i*j]=false;
	for(i=2;i<=n;i++) 
		if(a[i])
		{
			printf("%d ",i);
			t++;
			if(t%5==0)printf("\n");
		}
	
	
	return 0;
}

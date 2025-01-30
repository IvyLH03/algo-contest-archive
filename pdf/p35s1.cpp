#include<cstdio>
using namespace std;
int main()
{
	int n,f=1,j,i,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i+=1)
	{
		for(j=1;j<=i;j+=1)
		{
			f*=j;
		}
		s+=f;
		f=1; 
	}
	printf("%d",s);
	return 0;
}

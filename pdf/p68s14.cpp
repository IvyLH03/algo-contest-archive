#include<cstdio>
#include<cmath>
#include<cstring>
bool ss[5001];
using namespace std;
void pss(bool ss[],int n)
{
	ss[1]=ss[0]=0;
	for(int i=2;i<=sqrt(n);i++)
	{
		for(int j=3;j<=n;j++)
			if(j%i==0&&j!=i)ss[j]=0;
	}
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	memset(ss,1,sizeof(ss));pss(ss,n);
	
	for(int k=m;k>=2;k--)
		if(m%k==0&&ss[k]==1)
		{
			printf("%d",k);break;
		}
	
	for(int i=m+1;i<=n;i++)
	{
		for(int k=i;k>=2;k--)
		if(i%k==0&&ss[k]==1)
		{
			printf(",%d",k);break;
		}
	}
	return 0;
}

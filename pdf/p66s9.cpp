#include<cstdio>
#include<cstring> 
#include<cmath>
using namespace std;
bool ss[10001];

void pss(bool ss[],int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		for(int j=3;j<=n;j++)
			if(j%i==0&&j!=i)ss[j]=0;
	}
}

int main()
{
	int n,maxn=0;
	scanf("%d",&n);
	memset(ss,1,sizeof(ss));pss(ss,10001);
	for(int i=2;i<n;i++)
	{
		//printf(".\n");
		if(ss[i]==1&&ss[n-i]==1)
			if(i*(n-i)>maxn)maxn=i*(n-i);
	}
	printf("%d",maxn);
	return 0;
}

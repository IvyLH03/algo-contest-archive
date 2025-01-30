#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
bool sz[10001];
void zh(bool a[],int n)
{
	
	for(int i=2;i<=sqrt(n);i++)
	{
		for(int j=3;j<=n;j++)
			if(j%i==0&&j!=i)a[j]=0;
	}
}
void ssd(int a,int n,bool sz[])
{
	if(sz[a+2]==1)printf("%d %d\n",a,a+2);
}
int main()
{
	memset(sz,1,sizeof(sz));
	int n;
	scanf("%d",&n);
	zh(sz,n);
	for(int i=2;i<n;i++)
	{
		if(sz[i]==1)ssd(i,n,sz);
	}
	return 0;
}

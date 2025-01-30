#include<cstdio>
using namespace std;
int m,n,f[30001],v[26],p[26];
int max(int a,int b)
{
	return a>b? a:b; 
}
int main()
{
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&v[i],&p[i]);
		p[i]*=v[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=m;j>=v[i];j--)
		{
			f[j]=max(f[j],f[j-v[i]]+p[i]);
		}
	}
	printf("%d",f[m]);
	return 0;
} 

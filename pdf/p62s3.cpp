#include<cstdio>
#include<cstring>
using namespace std;
char nm[10001][101],huanzhe[10001][101];
float fs[10001];
bool ks[10001];
bool pfs(float x); 
bool pks(bool x);
int main()
{
	int n,j=0;     
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%f%d",nm[i],&fs[i],&ks[i]);
		if(pks(ks[i])==pfs(fs[i])==1)
			strcpy(huanzhe[++j],nm[i]);
	}
	printf("%d\n",j);
	for(int i=1;i<=j;i++)
		printf("%s\n",huanzhe[i]);
}
bool pfs(float x)
{
	if(x>=37.5)return 1;
	return 0;
}
bool pks(bool x)
{
	if(x)return 1;
	return 0;
}

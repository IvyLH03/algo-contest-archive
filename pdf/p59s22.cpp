#include<cstdio>

using namespace std;
char s[101][21];
int f[101];
int main()
{
	int n,i,maxn=0,smaxn;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%s",&f[i],s[i]);
		if(f[i]>maxn)
		{
			maxn=f[i];smaxn=i;
		}
	}
	printf("%s",s[smaxn]);
	return 0;
}

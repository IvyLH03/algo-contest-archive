#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[101],s[101];
int main()
{
	int n,r,j=0,minx=0;
	scanf("%d%d",&n,&r);
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		j++;
		if(j==r+1)j=1;
		s[j]+=a[i];
		minx+=s[j];
	}
	printf("%d",minx);
	return 0;
	
}

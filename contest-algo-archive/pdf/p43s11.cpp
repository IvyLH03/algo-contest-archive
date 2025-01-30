#include<cstdio>
using namespace std;
int a[10001];
int main()
{
	int m,i,maxn=0,minn=10001;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxn)
			maxn=a[i];
		if(a[i]<minn)
			minn=a[i];
	}
	printf("%d",maxn-minn);
	return 0;
}

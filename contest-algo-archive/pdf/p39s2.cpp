#include<cstdio>
using namespace std;
const int n=10;
int a[n+1];
int main()
{
	int i,gao,s=0;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&gao);
	gao+=30;
	for(i=1;i<=n;i++)
		if(a[i]<=gao)
			s++;
	printf("%d",s);
	return 0;
}

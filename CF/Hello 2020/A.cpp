#include<cstdio>
using namespace std;
const int N=21;
int n,m,num;
char a[N][N],b[N][N];
int rd()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';c=getchar();
	}
	return x*f;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]);
	for(int i=1;i<=m;i++)
		scanf("%s",b[i]);
	scanf("%d",&num);int x;
	for(int i=1;i<=num;i++)
	{
		scanf("%d",&x);x=x%(m*n);
		if(!x) x=m*n;
		printf("%s",a[(x%n?x%n:n)]);
		printf("%s",b[(x%m?x%m:m)]);
		printf("\n");
	}
	return 0;
 } 

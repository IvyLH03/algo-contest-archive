#include<cstdio>
using namespace std;
const int N=200007;
int dir[N],n,m;
char nam[N][11];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%s",&dir[i],nam[i]);
	}
	int k,t,p=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&k,&t);
		if(k^dir[p]==0)
		{
			p-=t;if(p<=0) p=n+p;
		}
		else
		{
			p+=t;if(p>n) p=p-n;
		}
		
	}
	printf("%s",nam[p]);
	return 0;
}

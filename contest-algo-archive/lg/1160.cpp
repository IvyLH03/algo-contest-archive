#include<cstdio>
using namespace std;
const int N=100007;
int l[N],r[N],n,m,t;
int main()
{
	scanf("%d",&n);
	int x,k;t=1;
	for(int i=2;i<=n;i++)
	{
		scanf("%d%d",&x,&k);
		if(k==0)
		{
			if(t==x) t=i;
			r[l[x]]=i;
			l[i]=l[x];
			r[i]=x;
			l[x]=i;
		}
		else
		{
			l[r[x]]=i;
			r[i]=r[x];
			l[i]=x;
			r[x]=i;
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		r[l[x]]=r[x];
		l[r[x]]=l[x];
		l[x]=r[x]=0;
	}
	while(t)
	{
		printf("%d ",t);t=r[t];
	}
	return 0;
 } 

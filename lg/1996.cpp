#include<cstdio>
using namespace std;
bool bz[101];
int main()
{
	int n,m,t=0,s=0;
	scanf("%d%d",&n,&m);
	int nn=n;
	while(nn)
	{
		if((++t)>n) t=1;
		if(bz[t]) continue;
		s++;
		if(s==m)
		{
			nn--;bz[t]=1;s=0;printf("%d ",t);
		}
	}
	return 0;
} 

#include<cstdio>
using namespace std;
int n,r;
void search(int t)
{
	int i,j,k;
		for(j=t+1;j<=n;j++)
			for(k=j+1;k<=n;k++)
					printf("%d %d %d\n",t,j,k);
	if(t!=(n-2))search(t+1);
	
}
int main()
{
	scanf("%d%d",&n,&r);
	search(1);
	return 0;
}

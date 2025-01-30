#include<cstdio>
using namespace std;
bool a[5001];
int main()
{
	int n,m,i,j,nn=0;
	scanf("%d%d",&n,&m);
	for(i=2;i<=m;i++)
		for(j=1;j<=n;j++)
			if(j%i==0)
			{
				if(a[j]==1)a[j]=0;
				else a[j]=1;
			}
//	for(i=1;i<=n;i++)
//		printf("%d(%d)",i,a[i]); 
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
			if(nn==0)
				printf("%d",i);
			else
				printf(",%d",i);
			nn++;
	}
	return 0;
}

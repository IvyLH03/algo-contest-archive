#include<cstdio>
using namespace std;
int nc[10001],wz[10001];
int pnc(int dc,int nc[],int m)
{
	for(int i=1;i<=m;i++)
	{
		if(nc[i]==dc)return 1;
	}
	return 0;
}
void cc(int dc,int nc[],int m)
{
	int temp;
	for(int i=1;i<=m;i++)
	{
		if(nc[i]==0)
		{
			nc[i]=dc;dc=0;
		}
	}
	if(dc!=0)
	{	
		nc[1]=dc;
		for(int i=1;i<m;i++)
		{
			temp=nc[i];nc[i]=nc[i+1];nc[i+1]=temp;
		}
		
	}
}
int main()
{
	int m,n,s=0;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{	
		
		scanf("%d",&wz[i]);
		if(pnc(wz[i],nc,m)==0)
		{
			//printf("pnc.\n");
			cc(wz[i],nc,m);
			s++; 
		}
	}
	printf("%d",s);
	return 0;
	
}

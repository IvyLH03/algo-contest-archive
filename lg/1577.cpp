#include<cstdio>
using namespace std;
int n,m,len[10001];
bool pd(int x)
{
	int s=0,i;
	for(i=1;i<=n;i++)
		s+=len[i]/x;
	if(s<m)	return 0;
	return 1;
}
int main()
{
	int i,z=1,y=1000000001,mid;
	float c;
	scanf("%d%d",&n,&m);
	
	for(i=1;i<=n;i++)
	{
		scanf("%f",&c);
		len[i]=c*100;
		//if(len[i]>y) y=len[i];
		//if(len[i]<z) z=len[i];
	}
	
	
	while(z<=y)
	{
		mid=(z+y)/2;
		if(pd(mid)) 
			z=mid+1;
		else y=mid-1;
	}
	
	c=y/100;
	printf("%.2f",c);
	return 0;
}

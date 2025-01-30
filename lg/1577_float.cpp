#include<cstdio>
using namespace std;
int n,m;
float len[10001];
bool pd(float x)
{
	int s=0,i;
	for(i=1;i<=n;i++)
	{
		float y=len[
	}
	if(s<m)	return 0;
	return 1;
}
int main()
{
	int i;
	float z=0.01,y=10000001,mid;
	float c;
	scanf("%d%d",&n,&m);
	
	for(i=1;i<=n;i++)
	{
		scanf("%f",&len[i]);
		//if(len[i]>y) y=len[i];
		//if(len[i]<z) z=len[i];
	}
	
	
	while(z<=y)
	{
		mid=(z+y)/2;
		if(pd(mid)) 
			z=mid+0.01;
		else y=mid-0.01;
	}
	
	printf("%.2f",y);
	return 0;
}

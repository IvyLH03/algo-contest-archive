#include<cstdio>
using namespace std;
int main()
{
	int n,i,ss,sz,r=0;
	scanf("%d",&n);
	for(i=1;i<=n;i+=1)
	{
		scanf("%d%d",&ss,&sz);
		if((ss<=140&&ss>=90)&&(sz<=99&&sz>=60))
			r+=1;
		else
			r=0;	
	}
	printf("%d",r);
	return 0;
} 

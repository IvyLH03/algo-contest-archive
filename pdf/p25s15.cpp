#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,i,x,y,num,r=0;
	scanf("%d",&n);
	for(i=1;i<=n;i+=1)
	{
		scanf("%d%d%d",&x,&y,&num);
		r=r+ceil(sqrt(pow(x,2)+pow(y,2))/50+1.5*num);
	}
	printf("%d",r);
	
	return 0;
} 

#include<cstdio>
using namespace std;
int n,k,ans;
int main()
{
	scanf("%d%d",&n,&k);
	if(n%2)
	{
		if(!k)
		{
			printf("-1");
			return 0;
		}
		if(k<=2||n==3||n==5)ans=(n+1)/2;
		else ans=n-2;
	}
	else
	{
		if(k==1||k==0)
			ans=0;
		else
			ans=n-2; 
	}
	printf("%d",ans);
	return 0;
	
	
}

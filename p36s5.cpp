#include<cstdio>
using namespace std;
int main()
{
	int n,i,s=0,in,h;
	scanf("%d",&n);
	for(i=1;i<=n;i+=1)
	{
		in=i;
		while(in!=0)
		{
			h=in%10;
			if(h==1)
				s+=1;
			in/=10;
					
		}
		
	}
	printf("%d",s);
	return 0;
}

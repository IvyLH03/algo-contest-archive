#include<cstdio>
using namespace std;
int main()
{
	int m,n,i,in,h,s=0;
	scanf("%d%d",&m,&n);
	for(i=m;i<=n;i+=1)
	{
		in=i;
		while(in!=0)
		{
			h=in%10;
			if(h==2)
				s++;
			in/=10;
			
		}
	}
	printf("%d",s);
	return 0;
}

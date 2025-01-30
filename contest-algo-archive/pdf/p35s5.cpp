#include<cstdio>
using namespace std;
int main()
{
	int n,i,s,k,y=0,in;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		in=i;
		while(in!=0)
		{	
			s=in%10;
			in=(in-s)/10;
			if(s==1)y++;
		}
	}
	printf("%d",y);
	return 0;
}

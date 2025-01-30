#include<cstdio>
using namespace std;
int main()
{
	int ld,r,i,y=0,s,in;
	scanf("%d%d",&ld,&r);
	for(i=ld;i<=r;i++)
	{
		in=i;
		while(in!=0)
		{
			s=in%10;
			in-=s;in/=10;
			if(s==2)
				y++;
		}
	}
	printf("%d",y);
	return 0;
}

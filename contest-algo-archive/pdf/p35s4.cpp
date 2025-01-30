#include<cstdio>
using namespace std;
int main()
{
	int n,i,s=0,in,cin=0,h;
	scanf("%d",&n);
	for(i=1;i<=n;i+=1)
	{
		if(i%7!=0)
		{	
			in=i;
			while(in!=0)
			{	
				h=in%10;
				if(h==7)
					cin=1;
				in/=10;	
			}
			if(cin!=1)
				s+=(i*i);
			cin=0;
		}
	}
	printf("%d",s);
	return 0;
}

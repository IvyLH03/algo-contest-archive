#include<cstdio>
using namespace std;
int main()
{
	int k,i,a=0,b=0,c=0,d;
	scanf("%d",&k);
	for(i=1;i<=k;i+=1)
	{
		scanf("%d",&d);
		switch(d)
		{
			case 1:a+=1;break;
			case 5:b+=1;break;
			case 10:c+=1;
		}
	}
	printf("%d\n%d\n%d",a,b,c);
	return 0;
}

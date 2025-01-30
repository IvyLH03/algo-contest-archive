#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,re=0,x,y;
	scanf("%d%d%d",&a,&b,&c);
	for(x=0;x<=c/a;x+=1)
	{
		for(y=0;y<=c/b;y+=1)
		{
			if(a*x+b*y==c)
				re+=1;
		}
	}
	printf("%d",re);
	return 0;
}

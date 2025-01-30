#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,x,y,re=0;
	scanf("%d%d%d",&a,&b,&c);
	for(x=0;x<=c/a;x++)
	{
		for(y=0;y<=c/b;y++)
		{
			if(a*x+b*y==c)
				re+=1;
		}
	}
	printf("%d",re);
	return 0;
}

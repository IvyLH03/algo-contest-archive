#include<cstdio>
using namespace std;
int a[6]={'A','B','C','D','E','F'}; 
void zh(int x,int r,int d)
{
	if(x==0)return ;
	if(x/d<r)
	{
		if(x/d<10)printf("%d",x/d);
		else printf("%c",a[x/d-9]);
		zh(x%d,r,d/r);
	}
	else 
	{
		zh(x,r,d*r);
	}
} 
int main()
{
	int x,r;
	scanf("%d%d",&x,&r);
	zh(x,r,r);
	return 0;
}

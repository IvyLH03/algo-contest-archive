#include<cstdio>
using namespace std;
int main()
{
	int t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		if(y<=x&&y>=3&&x%y==0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

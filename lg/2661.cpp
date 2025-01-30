#include<cstdio>
using namespace std;
const int N=200000;
int fa[2*N],to[2*N],n;
bool flag;
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&to[i]);
		fa[i]=i;
	}
	int ans=0;
	while(++ans) 
	{
		for(i=1;i<=n;i++)
		{
			if(to[fa[i]]==i) 
			{
				printf("%d",ans);return 0;
			}
			fa[i]=to[fa[i]];
		} 
	}
	printf("%d",ans);
	return 0;
}

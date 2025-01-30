#include<cstdio>
using namespace std;
int n,m,father[10001],t;
int find(int x)
{
	if(father[x]!=x) return father[x]=find(father[x]);
	return x;
}
void unionn(int x,int y)
{
	father[find(x)]=find(y);
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,x,y;
	for(i=1;i<=n;i++)
		father[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
			unionn(x,y);
		if(t==2)
		{
			if(find(x)==find(y))
				printf("Y\n");
			else printf("N\n");
		}
		
	}
	return 0;
}

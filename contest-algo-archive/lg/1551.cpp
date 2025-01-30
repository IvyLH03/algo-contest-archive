#include<cstdio>
using namespace std;
int n,m,p,father[5001];
int find(int x)
{
	if(father[x]!=x) return find(father[x]);
	return x;
}
void unionn(int a,int b)
{
	father[a]=b;
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	int i;
	for(i=1;i<=n;i++)
	{
		father[i]=i;
	}
	int a,b,r1,r2;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		r1=find(a);r2=find(b);
		if(r1!=r2)
			unionn(r1,r2);
	}
	for(i=1;i<=p;i++)
	{
		scanf("%d%d",&a,&b);
		if(find(a)==find(b))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
	
}


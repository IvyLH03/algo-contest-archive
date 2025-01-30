#include<cstdio>
using namespace std;
int m,n,q,father[20001];
int find(int x)
{
	if(father[x]!=x) return find(father[x]);
	return x;
}
int unionn(int a,int b)
{
	father[a]=b;
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,r1,r2,a,b;
	for(i=1;i<=n;i++)
		father[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		r1=find(a);
		r2=find(b);
		if(r1!=r2)
			unionn(r1,r2);
	}
	
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&a,&b);
		r1=find(a);
		r2=find(b);
		if(r1==r2)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
	
}

#include<cstdio>
using namespace std;
int main()
{
	int i,j,l,m,b,c;
	scanf("%d%d",&l,&m);
	
	int s=l+1;
	bool a[s];
	for(i=0;i<=s;i++)
		a[i]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&b,&c);
		for(j=b;j<=c;j++)
			a[j]=1;
	}
	for(i=0;i<=l;i++)
		if(a[i]==1)
			s-=1;
	printf("%d",s);
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
int a[200001];
struct node{
	int num;
	int name;
}b[10001]; 
int main()
{
	int m,n=1;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+m);
			for(int i=1;i<=m;i++)
				printf("%d ",a[i]);
	int t=0;
	b[1].name=a[1];
	while(t<=m)
	{
		if(a[++t]!=b[n].name)
			b[++n].name=a[n];
		b[n].num++;
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",b[i].name,b[i].num);
	return 0;
}

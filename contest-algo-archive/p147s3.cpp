#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int index;
	float data;
}a[101];
bool comp(node i,node j)
{
	return i.data>j.data;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%f",&a[i].index,&a[i].data);
	sort(a+1,a+1+n,comp);
	printf("%d %g",a[k].index,a[k].data);
	return 0;
}

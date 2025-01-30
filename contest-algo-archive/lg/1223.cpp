#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int index;
	int w;
}a[1001];
bool comp(node i,node j)
{
	return i.w<j.w;
}
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].w);
		a[i].index=i;
	}
	sort(a+1,a+1+n,comp);
	int s=0;
	double h=0;
	for(int i=1;i<n;i++)
	{
		printf("%d ",a[i].index);
		h+=s;
		s+=a[i].w;
		
	}
	printf("%d\n",a[n].index);
	h+=s;
	printf("%.2lf",h/n);
	return 0;
}

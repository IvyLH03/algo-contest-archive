#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int s,e;
}a[1000001];
bool comp(node i,node j)
{
	return i.e<j.e;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].s,&a[i].e);
	sort(a+1,a+1+n,comp);
	
	int s=a[1].e,tot=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i].s>=s)
		{
			s=a[i].e;
			tot++;
		}
	}
	printf("%d",tot);
	return 0;
	
} 

#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int fs;
	char name[21];
}a[101];
bool comp(node i,node j)
{
	return i.fs>j.fs;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%s",&a[i].fs,a[i].name);
	sort(a+1,a+1+n,comp);
	printf("%s",a[1].name);
	return 0;
}

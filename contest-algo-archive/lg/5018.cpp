#include<cstdio> //P5018
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int num,ls,rs;
}a[100006];
int f[100006],f2[100006];
int dfs(int x)
{
	if(x==-1)
		return 0;
	if(a[x].ls==-1&&a[x].rs==-1)
		return a[x].num;
	if(dfs(a[x].ls)==dfs(a[x].rs))
	{
		f[x]=f[a[x].ls]+f[a[x].rs]+1;
	}
	else
		f[x]=max(f[a[x].ls],f[a[x].rs]);
}
int main()
{
	int n;
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i].num);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].ls,&a[i],rs);
		f[i]=1;
	}
	
} 

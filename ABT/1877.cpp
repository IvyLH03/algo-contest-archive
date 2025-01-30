#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,bl,ml,c[51],f[51][1001],ans;  //用f表示l的变化量 
bool flag;
int main()
{
	int i,j,k;
	scanf("%d%d%d",&n,&bl,&ml);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	
	
	for(i=1;i<=n;i++)
	{	
		for(j=c[i];j<=ml;j++)
			f[i][j]=max(f[i][j],f[i-1][j-c[i]]+c[i]);
		for(j=0;j<=ml;j++)
			f[i][j]=max(f[i][j],f[i-1][j+c[i]]-c[i]);
	}
		

	for(i=0;i<=ml;i++)
	{
		f[n][i]+=bl; 
		if(f[n][i]>ans&&f[n][i]<=ml)
		{
			flag=1;ans=f[n][i];
		}
	}
	if(!flag) printf("-1"); 
	else printf("%d",ans);
	return 0;
}

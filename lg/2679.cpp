#include<cstdio>
using namespace std;
const int N=1007,M=207;
int f[N][M][M],n,m,k,ans;
char a[N],b[M];
int dfs(int sa,int sb,int kk,int len)
{
	if(kk>k) return 0;
	printf("sa=%d,sb=%d,kk=%d,len=%d\n",sa,sb,kk,len);
	if(sb+len-1==m&&kk==k) return 1;
	int i=1,s=0;
	while(a[sa+i]==b[sb+i]&&a[sa+i]&&b[sb+i])					//这里开始出现可以用记搜保存的冗余状态 
	{						//			printf("sa=%d,sb=%d,kk=%d,len=%d\n",sa,sb,kk,len);				
		s+=dfs(sa+i,sb+i,kk,len+1);s%=1000000007;
		i++;
	}
	for(i=1;a[sa+i];i++)
	{					//	printf("*");
		if(a[sa+i]==b[sb+1]) s=(s+dfs(sa+i,sb+1,kk+1,1))%1000000007;
	}
	return s;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int i,j;
	getchar();
//	getchar();
	for(i=1;i<=n;i++)
		scanf("%c",&a[i]);
	getchar();
	for(i=1;i<=m;i++)
		scanf("%c",&b[i]);
	for(i=1;i<=n-k+1;i++)
	{
		if(a[i]==b[1]) 
		{				//		printf("*");
			ans+=dfs(i,1,1,1);
		}
	}
	printf("%d",ans);
	return 0;
}

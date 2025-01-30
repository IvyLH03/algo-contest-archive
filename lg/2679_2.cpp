#include<cstdio>			//´¿±©Á¦¡­¡­ 
using namespace std;
const int N=1007,M=207;
int n,m,k,ans;
char a[N],b[M];
int dfs(int sa,int sb,int kk,int len)
{
	if(sb+len-1==m&&kk==k) 
	{
		return 1;
	}
	if(kk>k||sa+len-1>=n||sb+len-1>=m) return 0;
	int i,s=0;
	if(a[sa+len]==b[sb+len]&&a[sa+len]&&b[sb+len])			
	{
		s=dfs(sa,sb,kk,len+1)%1000000007;
	}
	for(i=1;sa+len+i-1<=n;i++)
	{
		if(a[sa+len+i-1]==b[sb+len]) 
		{		//		printf("*");
			s=(s+dfs(sa+len+i-1,sb+len,kk+1,1))%1000000007;
		}
	}
	return s;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int i,j;
	getchar();
	getchar(); 
	gets(a+1);
	gets(b+1);
							//	printf("a[2]=%d\n",a[2]);
	for(i=1;i+k-1<=n;i++)
	{
		if(a[i]==b[1]) 
		{		//				printf("*");
			ans+=dfs(i,1,1,1);
		}
	}
	printf("%d",ans);
	return 0;
}

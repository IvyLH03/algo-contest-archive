#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,c[107][107],num[107],tot[107][107],ans,f[107][107][107];
bool map[107][11],flag;
int main()
{
	scanf("%d%d",&n,&m);
	char s1[17];
	int i,j,k,s=0,y,ii;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s1);
		for(j=0;j<=m-1;j++)
		{
			if(s1[j]=='P') map[i][j+1]=1;
		}
	}
								//		for(i=1;i<=n;i++)
								//		{
								//			for(j=1;j<=m;j++)
								//				printf("%d ",map[i][j]);
								//			printf("\n");
								//		}
							//	printf("%d",1<<m);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<(1<<m);j++)
		{
			if(j&(j<<1)||j&(j<<2)) continue;
			s=0;flag=0;
			for(k=0;k<m;k++)
			{
				if(j&(1<<k))
				{
					s++;
					if(!map[i][k+1])
					{
						flag=1;break;
					} 
				}
			}
			if(flag) continue;
			c[i][++num[i]]=j;
			tot[i][num[i]]=s;
		}
	}
	for(i=1;i<=num[1];i++)
	{
		f[1][i][0]=tot[1][i];
	}
	for(i=1;i<=num[2];i++)
	{
		for(j=1;j<=num[1];j++)
		{
			if(!(c[2][i]&c[1][j]))
				f[2][i][j]=max(f[2][i][j],f[1][j][0]+tot[2][i]);
		}
	}
	for(i=3;i<=n;i++)
	{
		for(j=1;j<=num[i];j++)
		{
			for(k=1;k<=num[i-1];k++)
			{
				for(ii=1;ii<=num[i-2];ii++)
				if(!(c[i][j]&c[i-1][k])&&!(c[i][j]&c[i-2][ii])&&!(c[i-1][k]&c[i-2][ii]))
				{
					f[i][j][k]=max(f[i][j][k],f[i-1][k][ii]+tot[i][j]);
				}
			}
		}
	}
	ans=0;
	for(i=1;i<=num[n];i++)
		for(j=1;j<=num[n-1];j++)
			ans=max(ans,f[n][i][j]);
	printf("%d",ans);
	return 0;
}

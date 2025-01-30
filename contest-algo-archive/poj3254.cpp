#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,map[17],c[1107],f[17][1107],tot[1107],num;
void test()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=num;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}
	int s2,x,flag;
//	for(i=1;i<=num;i++)
//	{
//		s2=c[i];x=64;flag=0;
//		while(s2&&x)
//		{
//			if(s2/x)
//			{
//				printf("1");flag=1;
//			}
//			else
//			{
//				if(flag) printf("0");
//			}								
//			s2=s2%x;x/=2;
//		}
//		printf("\n");
//	} 
//	for(i=1;i<=num;i++)
//		printf("%d ",c[i]);
//	printf("\n");
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j,k,s;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&k);
			map[i]=map[i]<<1;
			if(!k) map[i]++;
		}
						//		for(i=1;i<=n;i++)
						//			printf("%d ",map[i]);
		
		
	for(i=0;i<(1<<m);i++)
	{
		if((i&(i<<1))||(i&(i>>1))) continue;
		c[++num]=i;
	}
							//printf("%d",num);
//	for(i=1;i<=n;i++)
		for(j=1;j<=num;j++)
		if(!(map[1]&c[j]))
		 	f[1][j]=1;
	
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=num;j++)
		{
			if(!(c[j]&map[i]))
			{
				for(k=1;k<=num;k++)
				{
					if(!(c[j]&c[k]))
						f[i][j]+=f[i-1][k];
				}
			}
		}
	}
	
//	test();
							
	int ans=0;
	
	for(i=1;i<=num;i++)
	//	if(!c[i]&map[n])
		ans+=f[n][i];
	printf("%d",ans%100000000);
	return 0;
	
}

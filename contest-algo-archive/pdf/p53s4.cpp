#include<cstdio>
#include<cstring>
using namespace std;
char s1[101][9],s2[101][9];
int y[101];
int main()
{
	char sc[9]="Scissors",rk[5]="Rock",ppr[6]="Paper";
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s%s",s1[i],s2[i]);
		if((strcmp(sc,s1[i])==0&&strcmp(ppr,s2[i])==0)||(strcmp(ppr,s1[i])==0&&strcmp(rk,s2[i])==0)||(strcmp(rk,s1[i])==0&&strcmp(sc,s2[i])==0))
			y[i]++;
		else 
		{
			if(strcmp(s1[i],s2[i])!=0) y[i]--;
		}
	}
	
//	for(i=1;i<=n;i++)
//		printf("%d ",y[i]);
	for(i=1;i<=n;i++)
	{
		if(y[i]==0)printf("Tie");
		else 
		{
			if(y[i]==1)printf("Player1");
			else printf("Player2");
		}
		printf("\n");
	}
	return 0; 
}

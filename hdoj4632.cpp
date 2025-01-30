#include<cstdio>
#include<cstring>
#include<algorithm>
char s[1001];
int f[1001][1001],T,a[1001];
using namespace std;
int main()
{
	int i,j,k,iiiii;
	scanf("%d",&T);
	for(iiiii=1;iiiii<=T;iiiii++)
	{
		
		memset(f,0,sizeof(f));
		scanf("%s",s);
		int len=strlen(s);
		for(i=1;i<=len;i++)
		{
			a[i]=s[i-1];
			f[i][i]=1;
		}
		
		for(k=1;k<=len;k++)
		{
			for(i=len-k;i>=1;i--)
			{
				j=i+k;
				f[i][j]=(f[i+1][j]+f[i][j-1]-f[i+1][j-1])%10007;
				if(a[i]==a[j]) f[i][j]=(f[i][j]+1+f[i+1][j-1])%10007;
			}
		}
			
		printf("Case %d: %d\n",iiiii,f[1][len]%10007);
		
	}
	return 0;
}

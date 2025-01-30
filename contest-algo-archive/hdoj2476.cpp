#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s1[107],s2[107];
int f[107][107];
int main()
{
	int i,j,k,len;
	while(~scanf("%s%s",s1,s2))
	{
		memset(f,0,sizeof(f));
		len=strlen(s1);
		for(k=1;k<=len;k++)
			for(i=0;i+k<=len;i++)
			{
				f[i][i+k-1]=f[i+1][i+k-1]+1;
				for(j=i+1;j<=i+k-1;j++)
				 {
				 	if(s2[j]==s2[i])
				 		f[i][i+k-1]=min(f[i][i+k-1],f[i+1][j]+f[j+1][i+k-1]);
				 }
			}
							//	printf("%d",f[0][len-1]); 
		for(i=0;i<len;i++)
		{
			if(s1[i]==s2[i])
			{
				if(i)
					f[0][i]=f[0][i-1];
				else
					f[0][i]=0;
			}
			else
			{
				for(k=0;k<=i;k++)
					f[0][i]=min(f[0][i],f[0][k]+f[k+1][i]);
			}
		}
		printf("%d\n",f[0][len-1]);
	}
	return 0;
} 

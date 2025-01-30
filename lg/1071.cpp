#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=107,M=27;
char s1[N],s2[N],s3[N];
int nw[M],od[M],cnt;
int main()
{
	scanf("%s%s",s1,s2);
	int len=min(strlen(s1),strlen(s2));
	for(int i=0;i<len;i++)
	{
		if((nw[s1[i]-'A'+1]&&nw[s1[i]-'A'+1]!=s2[i]-'A'+1)||(od[s2[i]-'A'+1]&&od[s2[i]-'A'+1]!=s1[i]-'A'+1))
		{
			printf("Failed");return 0;
		}
		if(!nw[s1[i]-'A'+1]) cnt++;
		nw[s1[i]-'A'+1]=s2[i]-'A'+1; 
		od[s2[i]-'A'+1]=s1[i]-'A'+1;
	}
	if(cnt<26)
	{
		printf("Failed");return 0;
	}
	scanf("%s",s3);
	len=strlen(s3);
	for(int i=0;i<len;i++)
	{
		printf("%c",nw[s3[i]-'A'+1]+'A'-1);
	}
	return 0;
}

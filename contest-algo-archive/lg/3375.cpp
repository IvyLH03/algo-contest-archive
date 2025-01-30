#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e6+7;
char s1[N],s2[N];
int next[N];
int main()
{
	scanf("%s%s",s1+1,s2+1);
	int len1=strlen(s1+1),len2=strlen(s2+1); 
	int p=0;
	for(int i=2;i<=len2;i++)
	{
		while(p&&s2[i]!=s2[p+1]) p=next[p];
		if(s2[i]==s2[p+1]) p++;
		next[i]=p;
	}
	p=0;
	
//	for(int i=0;i<len2;i++) printf("%d ",next[i]);
	for(int i=1;i<=len1;i++)
	{
		while(p&&s1[i]!=s2[p+1])
		{
		  	p=next[p];
		}
		if(s1[i]==s2[p+1]) p++;
		if(p==len2) 
		{
			printf("%d\n",i-len2+1);
			p=next[p];
		}
	}
	for(int i=1;i<=len2;i++) printf("%d ",next[i]);
	return 0;
	
		
} 

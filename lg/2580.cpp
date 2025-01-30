#include<cstdio>
#include<cstring>
using namespace std;
const int N=10000007;
int n,ttot;
struct node{
	int son[26];
	bool vis,flag;
}trie[N];
char s[51];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int len=strlen(s);
		int pos=0;
		for(int j=0;j<len;j++)
		{
			if(!trie[pos].son[s[j]-'a'])
			{
				trie[pos].son[s[j]-'a']=++ttot;pos=ttot;
			}
			else pos=trie[pos].son[s[j]-'a'];
		}
		trie[pos].flag=1;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int len=strlen(s),pos=0;
		bool flag=0;
		for(int j=0;j<len;j++)
		{
			if(!trie[pos].son[s[j]-'a'])
			{
				flag=1;break;
			}
			pos=trie[pos].son[s[j]-'a'];
		} 
		if(flag||(!trie[pos].flag)) 
		{
			printf("WRONG\n");continue;
		}
		if(trie[pos].vis) 
		{
			printf("REPEAT\n");continue;
		}
		trie[pos].vis=1;printf("OK\n");
	}
	return 0;
}

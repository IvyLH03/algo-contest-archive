#include<cstdio>
#include<cstring>
using namespace std;
struct node{
	int son[26];
	bool flag[1007],vis;
}t[500007];
int n,m,ttot;
char s[21];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d ",&m);
		for(int j=1;j<=m;j++)
		{
			scanf("%s",s);
			int len=strlen(s),pos=0;
			for(int k=0;k<len;k++)
			{
				if(!t[pos].son[s[k]-'a']) t[pos].son[s[k]-'a']=++ttot;
				pos=t[pos].son[s[k]-'a'];
			}
			t[pos].flag[i]=1;
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s);
		int len=strlen(s),pos=0;
		for(int j=0;j<len;j++) pos=t[pos].son[s[j]-'a'];
		for(int j=1;j<=n;j++) if(t[pos].flag[j]) printf("%d ",j);
		printf("\n");
	}
	return 0;
}

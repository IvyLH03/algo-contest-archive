#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3007;
int n,a1tot,a2tot,t1,t2,siz1[N],siz2[N],fa1[N],fa2[N];
char s1[N],s2[N];
int main()
{
	scanf("%d",&n);
	for(int k=1;k<=n;k++)
	{
		scanf("%s%s",s1,s2);
		a1tot=t1=siz1[1]=1;a2tot=t2=siz2[1]=1;
		int len1=strlen(s1),len2=strlen(s2);
		for(int i=0;i<len1;i++)
			if(s1[i]=='0') fa1[++a1tot]=t1,t1=a1tot,siz1[t1]=1;
			else t1=fa1[t1];
		for(int i=0;i<len2;i++)
			if(s2[i]=='0') fa2[++a2tot]=t2,t2=a2tot,siz2[t2]=1;
			else t2=fa2[t2];
		for(int i=1;i<=a1tot;i++)
			for(int j=fa1[i];j;j=fa1[j]) siz1[j]++;
		for(int i=1;i<=a2tot;i++)
			for(int j=fa2[i];j;j=fa2[j]) siz2[j]++;
		sort(siz1+1,siz1+1+a1tot);
		sort(siz2+1,siz2+1+a2tot);
		bool flag=0;
		for(int i=1;i<=a1tot;i++)
			if(siz1[i]!=siz2[i]) 
			{
				flag=1;break;
			}
		if(flag) printf("different\n");
		else printf("same\n");
	}
}

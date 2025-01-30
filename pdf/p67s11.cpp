#include<cstdio>
#include<cstring>
#include<cmath> 
using namespace std;
char ci[100];
int cs[26];
bool ss[100];
void pss(bool ss[])
{
	ss[0]=ss[1]=0;
	for(int i=2;i<=sqrt(100);i++)
	{
		for(int j=3;j<=100;j++)
			if(j%i==0&&j!=i)ss[j]=0;
	}
}
int main()
{
	memset(ss,1,sizeof(ss));pss(ss);
	gets(ci);
	int maxn=0,minn=101;
	for(int i=1;i<strlen(ci);i++)
		cs[ci[i]-'a']++;
	for(int i=0;i<26;i++)
	{
		if(cs[i]>maxn)maxn=cs[i];
		if(cs[i]<minn&&cs[i]!=0)minn=cs[i];
	}
	int y=maxn-minn;
	if(ss[y]==1)printf("Lucky Word\n%d",y);
	else printf("No Answer\n0");
	return 0;
} 

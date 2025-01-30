#include<cstdio>
#include<cstring>
using namespace std;
char sr[21][21],lt,ls[41][401];
int n,pd[21],maxn,gt[21][21];
void search(int i,int r)
{
	strcpy(ls[r+1],ls[r]);
	int j,k,len,lenr=strlen(ls[r]),lenr1;
	for(j=1;j<=n;j++)
	{
		if(gt[i][j]&&pd[j]<2)
		{
			len=strlen(sr[j]);
			for(k=gt[i][j];k<len;k++)ls[r+1][lenr+k-gt[i][j]]=sr[j][k];
			lenr1=strlen(ls[r+1]);
			if(lenr1>maxn)maxn=lenr1;
			pd[j]++;
			search(j,r+1);
			pd[j]--;
		}
		
	}
	return;
}
int pgt(char s1[],char s2[])
{
	int len1=strlen(s1),i,j,r=0;
	char ls1[21],ls2[21];
	bool t;
	for(i=len1-1;i>=1;i--)
	{
		for(j=i;j<=len1-1;j++)
		{
			ls1[++r]=s1[i];
		}
		for(j=1;j<=r;j++)
		{
			ls2[j]=s2[j];
		}
		if(strcmp(ls1,ls2)==0)return r;
		r=0;	
	}
	return 0;
}
int main()
{
	int i,j;
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)gets(sr[i]);
	scanf("%c",&lt);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if(i!=j)gt[i][j]=pgt(sr[i],sr[j]);
	}
	for(i=1;i<=n;i++)
	{
		if(sr[i][0]==lt)search(i,0);
	}
	printf("%d",maxn);
	return 0;
}

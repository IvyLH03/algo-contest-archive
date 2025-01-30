#include<cstdio>
#include<cstring>
using namespace std;
char s[30];
int a[30],b[30],c,d[30];
void fmult(int x[],int y,int z[])
{
	int s=0,r,p,i; 
	for(i=1;i<=29;i++)
	{
		r=x[i]*y+s;
		s=r/10;
		z[i]=r%10; 
	}
}
void fcpy(int x[],int y[])
{
	int i;
	for(i=1;i<=29;i++)
		x[i]=y[i];
}
void fprint(int x[])
{
	int len,i;bool flag=0;
	for(i=29;i>=1;i--)
		if(x[i])
		{
			len=i;flag=1;
			break;
		}
	if(!flag)
	{
		printf("0");return;
	}
	for(i=len;i>=1;i--)
		printf("%d",x[i]);
}
void fplus(int x[],int y[],int z[])
{
//	memset(d,0,sizeof(d));
	int sn=0,r,i;
	for(i=1;i<=29;i++)
	{
		r=x[i]+y[i]+sn;
		z[i]=r%10;
		if(r>=10) sn=1; 
	}
}
void fscan(int x[])
{
	memset(s,0,sizeof(s));
	gets(s);
	int len=strlen(s);
	for(int i=1;i<=len;i++)
		x[i]=s[len-i]-'0';
}
int main()
{
	fscan(a);fscan(b);
	fplus(a,b,a);
	fprint(a);
	return 0;
}

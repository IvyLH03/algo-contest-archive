#include<cstdio>
#include<cstring>
using namespace std;
int n,a[101],b[101],ans,i;
char s[101];
void init(int a[])
{
	scanf("%s",s);
	memset(a,0,sizeof(a));
	a[0]=strlen(s);
	for(i=1;i<=a[0];i++);
	{
		if(s[a[0]-i]>='0'&&s[a[0]-i]<='9')
			a[i]=s[a[0]-i]-'0';
		else a[i]=s[a[0]-i]-'A'+10;
	}
}
bool check(int a[])
{
	for(i=1;i<=a[0];i++)
		if(a[i]!=a[a[0]-i+1])return false;
	return true;
}
void jia(int a[])
{
	scanf("%d",&n);
	int i,k;
	for(i=1;i<=a[0];i++)b[i]=a[a[0]-i+1];
	for(i=1;i<=a[0];i++)a[i]+=b[i];
	for(i=1;i<=a[0];i++)
	{
		a[i+1]+=a[i]/n;
		a[i]%=n;
	}
	if(a[a[0]+1]>0)a[0]++;
}
int main()
{
	init(a);
	if(check(a))
	{
		printf("0\n");return 0;
	}
	ans=0;
	while(ans<=30)
	{
		ans++;
		jia(a);
		if(check(a))
		{
			printf("%d\n",ans);return 0;
		}
	}
	printf("Impossible");return 0;
}

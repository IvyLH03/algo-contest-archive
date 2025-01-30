#include<cstdio>
#include<cstring>
using namespace std;
char s[200007];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		s[1]=getchar();while(s[1]!='L'&&s[1]!='R') s[1]=getchar();
		int n=1;
		while(s[n]!='\n') s[++n]=getchar();
		n--;
		int ans=0,lastr=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='R') ans=ans>i-lastr?ans:i-lastr,lastr=i;
		}
		ans=ans>n+1-lastr?ans:n+1-lastr;
		printf("%d\n",ans);
	}
	return 0;
}

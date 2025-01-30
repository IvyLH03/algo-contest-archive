#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[101],ans[101],c;
int num[26],a[101];
bool flag,qi,bz[26];
int main()
{
	scanf("%s",s);
	int lens=strlen(s),i,j;
	for(i=0;i<lens;i++)
	{
		a[i+1]=s[i]-'a';
		num[a[i+1]]++;
	}
	
	sort(a+1,a+1+lens);
	
	i=1;int t=0;
	while(i<=lens)
	{
		if(num[a[i]]%2==0)
		{
			for(j=1;j<=num[a[i]]/2;j++)
				ans[++t]=a[i];
		}
		else
		{
			bz[a[i]]=1;
			for(j=1;j<=num[a[i]]/2+1;j++)
				ans[++t]=a[i];
		}
		i+=num[a[i]];
	}
	
	for(i=0;i<=25;i++)
	{
		if(!bz[i]&&i<ans[t])
		{
			c=i+'a';
			flag=1;
			break;
		}
	}
	
	for(i=1;i<=t;i++)
	{
		printf("%c",ans[i]+'a');
	}
	if(flag){
		printf("%c",c);
	}
	if(bz[ans[t]]&&!flag){
		t--;
	}
	for(i=t;i>=1;i--)
		printf("%c",ans[i]+'a');
	return 0;
}

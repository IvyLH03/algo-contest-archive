#include<cstdio>
#include<cstring>
using namespace std;
char s[1001];
int main()
{
	int k,i,j,n,y=0,sit=0;
	scanf("%d%s",&k,s);
	for(i=0;i<strlen(s);i++)
	{
		n=i;
		while(s[i]==s[n++])
		{
			y++;
		}
		
		//printf("y=%d\n",y);
			
		if(y>=k)
		{
			sit=i;break;
		}
		i+=y;y=0;
		//printf("i=%d\n",i);
	}
	printf("%c",s[sit]);
	return 0;
}

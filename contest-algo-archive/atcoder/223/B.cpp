#include<cstdio>
#include<cstring>
using namespace std;
const int N=1007;
char s[N],maxs[N],mins[N],curs[N];
int main()
{
	scanf("%s",s+1);
	int len = strlen(s+1);
	
	for(int i=1;i<=len;i++) maxs[i] = mins[i] = s[i];
	for(int i=2;i<=len;i++)
	{
		bool maybeMax = 0, maybeMin = 0;
		for(int j=i,k=1;j<=len;j++,k++) curs[k] = s[j];
		for(int j=1,k=len-i+2;j<i;j++,k++) curs[k] = s[j];
		for(int j=1;j<=len;j++) 
		{
			if(curs[j]==maxs[j]) continue;
			else if(curs[j]>maxs[j]) maybeMax=1;
			break;
		}
		for(int j=1;j<=len;j++) 
		{
			if(curs[j]==mins[j]) continue;
			else if(curs[j]<mins[j]) maybeMin=1;
			break;
		}
		if(maybeMax)
			for(int j=1;j<=len;j++) maxs[j]=curs[j];
		if(maybeMin)
			for(int j=1;j<=len;j++) mins[j]=curs[j];
	}
	printf("%s\n%s",mins+1,maxs+1);
	return 0;
}
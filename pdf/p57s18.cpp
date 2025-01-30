#include<cstdio>
#include<cstring>
using namespace std;
char s[201][101];
int main()
{
	int i=0,maxn=0,minn=101,k,smaxn,sminn;
	while((scanf("%s",s[i++]))==1);
	for(k=0;k<i-1;k++)
	{
		if(strlen(s[k])>maxn)
		{
			maxn=strlen(s[k]);smaxn=k; 
		}
		if(strlen(s[k])<minn)
		{
			minn=strlen(s[k]);sminn=k;
		}
	}
	printf("%s\n%s",s[smaxn],s[sminn]);
	return 0;
}

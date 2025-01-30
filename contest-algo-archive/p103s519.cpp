#include<cstdio>
#include<cstring>
using namespace std;
const int N=256;
char s1[N],s2[N],a[N],b[N];
int l1,l2;
int main()
{
	gets(s1);gets(s2);
	int i;
	strupr(s1);strupr(s2);
	for(i=0;i<strlen(s1);i++)
		if(s1[i]!=' ') a[l1++]=s1[i];
	for(i=0;i<=strlen(s2);i++)
		if(s2[i]!=' ') b[l2++]=s2[i];

	if(strcmp(a,b)==0) printf("YES\n");
	else printf("NO\n");
}

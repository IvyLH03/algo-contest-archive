#include<cstdio>
#include<cstring>
using namespace std;
char a[80];
int main()
{
	gets(a);
	int i;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]>='a'&&a[i]<='z')a[i]-=32;
		else if(a[i]>='A'&&a[i]<='Z')a[i]+=32;
	}
	puts(a);
	return 0;
}

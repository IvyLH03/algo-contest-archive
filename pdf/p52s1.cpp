#include<cstdio>
#include<cstring>
using namespace std;
char a[256];
int main()
{
	int j=0;
	gets(a);
	for(int i=0;i<strlen(a);i++)
		if(a[i]>='0'&&a[i]<='9') j++;
	printf("%d",j);
	return 0;
}

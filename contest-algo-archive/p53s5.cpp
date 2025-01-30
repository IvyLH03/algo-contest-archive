#include<cstdio>
#include<cstring>
using namespace std;
char st[101],y[101];
int main()
{
	int i;
	gets(st);
	for(i=0;i<strlen(st)-1;i++)
		y[i]=st[i]+st[i+1];
	y[strlen(st)-1]=st[0]+st[strlen(st)-1];
	puts(y);
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;
char a[501],b[501];
int main()
{
	int i,y=0;
	float yuzhi;
	scanf("%f",&yuzhi);
	scanf("%s%s",a,b);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]==b[i])y++;
	}
	if(1.0*y/strlen(a)>=yuzhi) printf("yes");
	else printf("no");
	return 0;
}

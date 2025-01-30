#include<cstdio>
using namespace std;
struct node{
	char name[9];
	float t;
	bool fs;
}a[200];
int main()
{
	int r=0,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s%f%d",a[i].name,&a[i].t,&a[i].fs);
	for(int i=1;i<=n;i++)
		if(a[i].t>=37.5&&a[i].fs)
		{
			printf("%s\n",a[i].name);
			r++;
		}
	printf("%d",r);
	return 0;
}

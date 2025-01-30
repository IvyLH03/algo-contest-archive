#include<cstdio>
#include<string>
using namespace std;
struct student{
	char name[11];
	int chinese,math,total;
}a[110];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%d%d",a[i].name,&a[i].chinese,&a[i].math);
		a[i].total=a[i].chinese+a[i].math;
	}
	for(int i=n;i>=2;i--)
		for(int j=1;j<=i;j++)
			if(a[j].total<a[j+1].total)
				swap(a[j],a[j+1]);
	for(int i=1;i<=n;i++)
		printf("%s %d %d %d\n",a[i].name,a[i].chinese,a[i].math,a[i].total);
	return 0;
} 

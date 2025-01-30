#include<cstdio>
using namespace std;
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n+1];
	float b[5]={};
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<=18)
			b[1]++;
		if(a[i]>18&&a[i]<=35)
			b[2]++;
		if(a[i]>35&&a[i]<=60)
			b[3]++;
		if(a[i]>=61)
			b[4]++;
	}
	for(i=1;i<=3;i++)
	{
		b[i]=b[i]*100/n;
		printf("%.2f%%\n",b[i]);
	}	
	printf("%.2f",b[4]*100/n);
	printf("%%");
	return 0;
}

#include<cstdio>
using namespace std;
int a[10001]={1},n,total;
int search(int,int);
int print(int);
int main()
{
	scanf("%d",&n);
	search(n,1);
	printf("total=%d\n",total);
	return 0;
}
int search(int s,int t)
{ 
	int i;
	for(i=a[t-1];i<=s;i++)
		if(i<n)
		{
			a[t]=i;
			s-=i;
			if(s==0)print(t);
			else search(s,t+1);
			s+=i;
		}
}
int print(int t)
{
	printf("%d=",n);
	for(int i=1;i<=t-1;i++)
		printf("%d+",a[i]);
	printf("%d\n",a[t]);
	total++;
}

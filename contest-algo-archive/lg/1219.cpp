#include<cstdio>
using namespace std;
int n,a[14],tot;
bool b[14],c[26],d[26];
int print();
int search(int t)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if((!b[i])&&(!c[i+t])&&(!d[i-t+n/2]))
		{
			a[t]=i;b[i]=1;c[i+t]=1;d[i-t+n/2]=1;
			if(t==n)print();
			else search(t+1);
			a[t]=0;b[i]=0;c[i+t]=0;d[i-t+n/2]=0;
		}
	}
}
int print()
{
	int i;
	if(++tot<=3)
	{
		for(i=1;i<=n-1;i++)printf("%d ",a[i]);
		printf("%d",a[n]); 
		printf("\n");
	}
}
int main()
{
	scanf("%d",&n);
	search(1);
	printf("%d",tot);
	return 0;
}

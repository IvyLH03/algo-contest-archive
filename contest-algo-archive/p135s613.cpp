#include<cstdio>
using namespace std;
const int max1=51;
int a[max1],n,m;
bool flag;
void sum(int n,int m)
{
	if(a[n]==m)flag=true;
	else if(n==1)return;
	else
	{
		sum(n-1,m-a[n]);
		sum(n-1,m);
	} 
}
int main()
{
	 scanf("%d",&n);
	 for(int i=1;i<=n;i++)scanf("%d",a[i]);
	 scanf("%d",m);
	 flag=false;
	 sum(n,m);
	 if(flag)printf("YES");
	 else printf("NO");
	 return 0;
}

#include<cstdio>
using namespace std;
bool a[101];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int ji=0,num=0,s=0;
	while(ji!=n)
	{
		num+=1;
		if(num==n+1)
			num=1;
		if(a[num]==0)
			s++;
		if(s==m)
		{	
			s=0;
			printf("%d ",num);
			a[num]=1;
			ji+=1;
		}
	}
	return 0;
}

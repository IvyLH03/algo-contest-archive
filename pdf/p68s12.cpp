#include<cstdio>
#include<cstring>
#include<cmath> 
using namespace std;
bool ss[1000],hw[1000];
void phw(bool hw[],int n)
{
	for(int i=11;i<=n;i++)
	{
		if(i/100==0)
		{ 
					//printf("%d\n",i);
			if(i/10==i%10)
			{
				hw[i]=1;		//	printf("%d\n",i);
			}
		}
		else if(i/100==i%10)hw[i]==1;
	}
}
void pss(bool ss[],int n)
{
	ss[0]=ss[1]=0;
	for(int i=2;i<sqrt(n);i++)
	{
		for(int j=3;j<=n;j++)
			if(j%i==0&&j!=i)ss[j]=0;
	}
}
int main()
{
	memset(ss,1,sizeof(ss));
	int n,s=0;
	scanf("%d",&n);
	phw(hw,n);pss(ss,n);
	for(int i=11;i<=n;i++)
		if(hw[i]==1&&ss[i]==1)s++;
	printf("%d\n",s);
	
			//printf("%d %d",hw[11],ss[11]);
	return 0;
}

#include<cstdio>
#include<cmath>
#include<cstring>
bool ss[100001];
using namespace std;
void pss(bool ss[],int y)
{
	ss[0]=ss[1]=0;
	for(int i=2;i<=sqrt(y);i++)
	{
		for(int j=3;j<=y;j++)
			if(j%i==0&&j!=i)ss[j]=0; 
	}
}
int main()
{
	int x,y,s=0;
	memset(ss,1,sizeof(ss));
	scanf("%d%d",&x,&y);
	pss(ss,y);
	for(int i=x;i<=y;i++)
		if(ss[i]==1)s++;
	printf("%d",s);
	return 0;
}

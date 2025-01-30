#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
void TurnData(int n,int a);
char ch[6]={'A','B','C','D','E','F'};
int main()
{
	int n;
	scanf("%d",&n);
	TurnData(n,2);
	TurnData(n,8);
	TurnData(n,16);
	return 0;	
}

void TurnData(int n,int a)
{
	int x[17],i,j,k=0,h;
	printf("%d turn into %d :",n,a);
	if(n<0)printf("-");
	j=abs(n);
	do
	{
		k++;
		i=j%a;
		j/=a;
		x[k]=i;
	}
	while(j!=0);
	for(h=k;h>=1;--h)
	 if(x[h]<10) printf("%d",x[h]);
	 else printf("%c",ch[x[h]-10]);
	printf("\n");
}

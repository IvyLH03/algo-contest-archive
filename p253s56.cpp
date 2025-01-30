#include<cstdio>
using namespace std;
int data[6][6]={{0,0,0,0,0,0},{0,13,11,10,4,7},
{0,13,10,10,8,5},{0,5,9,7,7,4},{0,15,12,10,11,5},{0,10,11,8,8,4}};
int maxl=0,g[10],f[10];
bool p[6]={0};
int go(int step,int t)
{
	for(int i=1;i<=5;i++)
		if(!p[i])
		{
			f[step]=i;
			p[i]=1;
			t+=data[step][i];
			if(step<5)go(step+1,t);
			else if(t>maxl)
			{
				maxl=t;
				for(int j=1;j<=5;j++)
				g[j]=f[j];
			}
			t-=data[step][i];
			p[i]=0;
		}
}
int main()
{
	char c=64;
	go(1,0);
	for(int i=1;i<=5;i++)
		 printf("%c:J%d ",c+i,f[i]);
		printf("\nsupply:%d",maxl);
	return 0; 
} 

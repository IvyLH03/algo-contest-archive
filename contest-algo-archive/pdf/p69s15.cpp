#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
bool ss[100001];
void pss(bool ss[])
{
	ss[0]=ss[1]=0;
	for(int i=2;i<=sqrt(100001);i++)
	{
		for(int j=3;j<=100001;j++) 
			if(j%i==0&&j!=i)ss[j]=0;
	}
}
int main()
	
{
	memset(ss,1,sizeof(ss));
	int m,n;scanf("%d%d",&m,&n);
	pss(ss);
	int r=0,dx=0,ws=0,s;
	for(int i=m;i<=n;i++)
	{
		if(ss[i]==1)
		{
			s=i;
			while(s!=0)
			{
				s/=10;
				ws++;
						
			}
			s=i;
			for(int j=ws;j>=0;j--)
			{
				ws--;
				dx+=s%10*pow(10,ws);
				s/=10;
				
			}
					//	printf("%d ",dx);
			if(ss[dx]==1)
			{
				if(r==0)printf("%d",i);
				else printf(",%d",i);
				r++;
			}
		} 
		ws=dx=0;
	}
	return 0;
}

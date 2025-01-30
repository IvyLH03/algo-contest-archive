#include<cstdio>
#include<cstring>
using namespace std;
int dx[2]={1,-1},que[100001][3],bz[100001];
int main()
{
	int n,k,i; 
	scanf("%d%d",&n,&k);
	int x,t=1,w=1;
	que[1][1]=n;que[1][2]=0;
	while(t<=w)
	{
		for(i=0;i<=2;i++)
		{
			
			if(i==2)x=que[t][1]*2;
			else x=que[t][1]+dx[i];
			if((bz[x]==0)&&(bz[x]<=100000)&&(bz[x]>=0))
			{
				w++;
				que[w][1]=x;
				que[w][2]=que[t][2]+1;
				bz[x]=0;
				if(x==k)
				{
					printf("%d\n",que[w][2]);
					return 0;
				}
			}
		}
		t++;
				//	printf("t=%d w=%d\n",t,w);
	}
	return 0;
}

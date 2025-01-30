//hdoj 2955 ·Ï¸å 
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,m,w[107],v[107],f[107];
int max(int a,int b)
{
	return a>b?a:b;
} 
int main()
{
	int iii,i,j;	double p;
	scanf("%d",&t);
	for(iii=1;iii<=t;iii++)
	{
		memset(f,0,sizeof(f));	//	printf("\ninput p,n\n");
		scanf("%lf%d",&p,&n);
		m=p*100;				//	printf("%d",m);
		for(i=1;i<=n;i++)
		{
			scanf("%d%lf",&v[i],&p);	printf("p=%lf\n",p);
			w[i]=p*100;			printf("w[%d]=%d\n",i,w[i]);
		}
				
		for(i=1;i<=n;i++)
			for(j=m;j>=w[i];j--)
				f[j]=max(f[j],f[j-w[i]]+v[i]);
				
		printf("%d\n",f[m]);
	}
}

#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,f[20001];
struct node{
	int q,t;
}a[20001];
bool comp(node a,node b)
{
	return a.q>b.q;
}
int main()
{
	scanf("%d%d",&n,&k);
	int i;
	for(i=1;i<=k;i++)
		scanf("%d%d",&a[i].q,&a[i].t);
	sort(a+1,a+1+k,comp);
			//printf("sort:\n");
			//for(i=1;i<=k;i++)
			//{
				//printf("%d %d\n",a[i].q,a[i].t);
				//printf("%d. q=%d,t=%d\n",i,a[i].q,a[i].t);
			//}
	int t=1;
	for(i=n;i>=1;i--)
	{
		if(a[t].q!=i)
			f[i]=f[i+1]+1;
		else
		{
			while(a[t].q==i)
			{
				f[i]=max(f[i],f[i+a[t].t]);
				t++;
			}
		}
	}
				//printf("f:\n");
				//for(i=1;i<=n;i++)
				//{
				//	printf("f[%d]=%d\n",i,f[i]);
				//}
	printf("%d",f[1]);
	return 0;
}


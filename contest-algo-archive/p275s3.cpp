#include<cstdio>
#include<algorithm>
using namespace std;
float res[10001];
struct node{
	int n;
	int v;
	float r;
}a[101];
bool comp(node i,node j)
{
	return i.r>j.r;
}
int main()
{
	int k,w,s,c=0;
	float y=0;
	scanf("%d",&k);
	for(int g=1;g<=k;g++)
	{
		y=0;
		scanf("%d%d",&w,&s);
		for(int i=1;i<=s;i++)
		{
			scanf("%d%d",&a[i].n,&a[i].v);
			a[i].r=1.0*a[i].v/a[i].n;
		}
		sort(a+1,a+1+s,comp);
		int i=0;
		while(c<w&&i<=s)
		{
			i++;
			if(a[i].n<w-c)
			{
				c+=a[i].n;
				y+=a[i].v; 
			}
			else 
			{
				y+=(w-c)*a[i].r;
				c=w;
			}
			
		}
		res[g]=y;
	}
	for(int i=1;i<=k;i++)
		printf("%.2f\n",res[i]);
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;
int a[10001],b[10001],h[10001];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,j,k,x,n,maxx,m;
	i=1;n=0;m=0;
	while(scanf("%d",&a[i])==1)
	{
		maxx=0;
		for(j=1;j<=i-1;j++)
			if(a[j]>=a[i])
				if(b[j]>maxx)
					maxx=b[j];
		b[i]=maxx+1;
		if(b[i]>m)
			m=b[i];
		x=0;
		for(k=1;k<=n;k++)
			if(h[k]>=a[i])
			{
				if(x==0)
					x=k;
				else if(h[k]<h[x])
					x=k;
			}
		if(x==0)
		{
			n++;x=n;
		}
		h[x]=a[i];
		i++;
	}
	printf("%d\n%d",m,n);
	return 0;
	
}

#include<cstdio>
using namespace std;
int n,m,f[32001],v[61][3],w[61][3];
int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	scanf("%d%d",&m,&n);
	int i,j,x,y,z,t=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(!z)
		{
			v[i][0]=x*y;
			w[i][0]=x;
		}
		else
		{
			if(v[z][1]==0)
			{
				v[z][1]=x*y;
				w[z][1]=x;
			}
			else
			{
				v[z][2]=x*y;
				w[z][2]=x;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(w[i][0])
			for(j=m;j>=w[i][0];j--)
			{
				f[j]=max(f[j],f[j-w[i][0]]+v[i][0]);
				if(j>=w[i][0]+w[i][1]+w[i][2])
					f[j]=max(f[j],f[j-(w[i][0]+w[i][1]+w[i][2])]+v[i][0]+v[i][1]+v[i][2]);
				if(j>=w[i][0]+w[i][1])
					f[j]=max(f[j],f[j-(w[i][0]+w[i][1])]+v[i][0]+v[i][1]);
				if(j>=w[i][0]+w[i][2])
					f[j]=max(f[j],f[j-(w[i][0]+w[i][2])]+v[i][0]+v[i][2]);
			}
	}
	printf("%d",f[m]);
	return 0;
}

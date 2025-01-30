//luogu P1064  (°ë±©Á¦Ã¶¾Ù·¨dp£¬AC)
#include<cstdio>
#include<cstring>
using namespace std;
int f[32007],n,m,w[67][3],v[67][3];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	scanf("%d%d",&m,&n);
	int i,j,a,b,c;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(!c)
		{
			w[i][0]=a;v[i][0]=a*b;
		}
		else
		{
			if(w[c][1]||v[c][1])
				w[c][2]=a,v[c][2]=a*b;
			else
				w[c][1]=a,v[c][1]=a*b;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(w[i][0]||v[i][0])
			for(j=m;j>=w[i][0];j--)
			{
				f[j]=max(f[j],f[j-w[i][0]]+v[i][0]);
				if(j>=w[i][0]+w[i][1]+w[i][2])
				 	f[j]=max(f[j],f[j-w[i][0]-w[i][1]-w[i][2]]+v[i][0]+v[i][1]+v[i][2]);
				if(j>=w[i][0]+w[i][1])
				 	f[j]=max(f[j],f[j-w[i][0]-w[i][1]]+v[i][0]+v[i][1]);
				if(j>=w[i][0]+w[i][2])
					f[j]=max(f[j],f[j-w[i][0]-w[i][2]]+v[i][0]+v[i][2]);
				
			}
	}
	printf("%d",f[m]);
	return 0;
}


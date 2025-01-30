#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,c,d[57],p[57],f[57][57][2],p2[57],ans;
int main()
{
	int i,j,k,len;
	memset(f,127/3,sizeof(f));
	scanf("%d%d",&n,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&d[i],&p[i]);
		p2[i]=p2[i-1]+p[i];
	}
	f[c][c][0]=f[c][c][1]=0;
	for(len=1;len<=n;len++)
	{
		for(i=1;i+len<=n;i++)
		{
			j=i+len;
			f[i][j][0]=min(f[i][j][0],f[i+1][j][0]+(p2[i]+p2[n]-p2[j])*(d[i+1]-d[i]));
			f[i][j][0]=min(f[i][j][0],f[i+1][j][1]+(p2[i]+p2[n]-p2[j])*(d[j]-d[i]));
			f[i][j][1]=min(f[i][j][1],f[i][j-1][0]+(p2[i-1]+p2[n]-p2[j-1])*(d[j]-d[i]));
			f[i][j][1]=min(f[i][j][1],f[i][j-1][1]+(p2[i-1]+p2[n]-p2[j-1])*(d[j]-d[j-1]));
		}
	}
	ans=min(f[1][n][1],f[1][n][0]);
	printf("%d",ans);
	return 0;
}

#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std; 
const int N=100007;
int n,k,f1[N][30],f2[N][30];
int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&f1[i][0]);
		f2[i][0]=f1[i][0];
	}
	for(j=1;j<=17;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			f1[i][j]=max(f1[i][j-1],f1[i+(1<<j-1)][j-1]);
			f2[i][j]=min(f2[i][j-1],f2[i+(1<<j-1)][j-1]);	//Ã»¿¼ÂÇÎ´¸³Öµ×´Ì¬ 
		}
	} 
	int s=log2(k),ans1,ans2;
	for(i=1;i<=n-k+1;i++)
	{
		ans1=max(f1[i][s],f1[i+k-(1<<s)][s]);
		ans2=min(f2[i][s],f2[i+k-(1<<s)][s]);
		printf("%d %d\n",ans1,ans2);	
	}
	return 0;
}

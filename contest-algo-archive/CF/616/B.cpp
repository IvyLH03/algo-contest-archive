#include<cstdio>
using namespace std;
int n,t,a[300007];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
		int p1=0,p2=n+1;
		while(p1<=n&&a[++p1]>=p1-1);
		while(p2>=1&&a[--p2]>=n-p2);
		p1--;p2++;
		if(p2<=p1||p1==n||p2==1) printf("Yes\n");
		else printf("No\n");
		
	}
	return 0;
}

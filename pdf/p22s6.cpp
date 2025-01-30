#include<cstdio>
using namespace std;
int main()
{
	int n,a,b,c,gold,sliver,bronze,i,all=0;
	scanf("%d",&n);
	for(i=1;i<=n;i+=1)
	{
		scanf("%d%d%d",&a,&b,&c); 
		gold+=a;
		sliver+=b;
		bronze+=c;
		all=all+a+b+c;
	}
	printf("%d %d %d %d",gold,sliver,bronze,all);
	return 0;
}

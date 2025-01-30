#include<cstdio>
using namespace std;
const int N=100007;
int len[N], v[N], n;
double totTime, ans, t[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&len[i],&v[i]);
		t[i] = 1.0*len[i]/v[i];
		totTime += t[i];
	}
	totTime /= 2;
	for(int i=1;i<=n;i++)
	{
		if(totTime - t[i] <= 0)
		{
			ans += v[i] * totTime;break;
		}
		else
		{
			totTime -= t[i]; ans += len[i];
		}
	}
	printf("%lf",ans);
	return 0;
}
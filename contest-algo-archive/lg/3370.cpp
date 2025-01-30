#include<cstdio>
#include<algorithm>
#include<cstring>
#define ull unsigned long long
using namespace std;
const int N=10007,base1=131,base2=2333;
struct node{
	ull a,b;
}h[N];
int n,ans;
char s[N];
ull hash1(char s[])
{
	int len=strlen(s);ull res=0;
	for(int i=0;i<len;i++) res=res*base1+(ull)s[i];
	return res;
		
}
ull hash2(char s[])
{
	int len=strlen(s); ull res=0;
	for(int i=0;i<len;i++) res=res*base2+(ull)s[i];
	return res;
}
bool cmp(node x,node y)
{
	if(x.a!=y.a) return x.a<y.a;
	return x.b<y.b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		h[i].a=hash1(s);h[i].b=hash2(s);
	}
	sort(h+1,h+1+n,cmp);
//	for(int i=1;i<=n;i++) printf("%llu ",a[i]);printf("\n");
//	for(int i=1;i<=n;i++) printf("%llu ",b[i]);printf("\n");
	ans=1;
	for(int i=1;i<n;i++) if(h[i].a!=h[i+1].a||h[i].b!=h[i+1].b) ans++;
	printf("%d\n",ans);
	return 0;
}

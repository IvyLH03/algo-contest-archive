#include<cstdio>//1823
const int N=5e5;
int n,stack[N],a,ans,top,s,y;
bool flag;
int main()
{
	int i,j,k;
	scanf("%d",&n);
	scanf("%d",&stack[1]);
	top=1;
	s=1;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&a);
		//s=top;
		//while(a>=stack[s]&&s)
		s=top;
		while(a>stack[top]&&top)
		{
			ans++;top--;
		}
		y=top;
		while(a==stack[y]&&y)
		{
			ans++;y--;
		}
		stack[++top]=a;
		ans++;
	}
	printf("%d",ans);
	return 0;
}

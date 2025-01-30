#include<cstdio>
#include<algorithm>
using namespace std;
int a[10001];
int main()
{
    int n,c,d,i;
    scanf("%d%d%d",&n,&c,&d);
    c+=d;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int t=0,tot=0;i=0;
    while(t+a[++i]<=c)
    {			
    	t+=a[i];
		tot++;
    }
    printf("%d",tot);
    return 0;
}

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int d,g,ans,f[107][107];
bool flag;
struct node{
    int t,f,h;
}a[107];
bool comp(node x,node y)
{
    return x.t<y.t;
}
int main()
{
    int i,j,k,n=0;ans=100000007;
    scanf("%d%d",&d,&g);
    for(i=1;i<=g;i++)
    {
        scanf("%d%d%d",&a[i].t,&a[i].f,&a[i].h);
        n+=a[i].h;
    }
    ans=100000007;
    sort(a+1,a+1+g,comp);
    memset(f,-1,sizeof(f));
    f[0][0]=10;
    
    for(i=1;i<=g;i++)
    {
        for(j=n;j>=0;j--)
        {
        	if(j>=a[i].h)
            	if(a[i].t<=f[i-1][j-a[i].h])
                f[i][j]=max(f[i][j],f[i-1][j-a[i].h]);
            if(a[i].t<=f[i-1][j])
                f[i][j]=max(f[i][j],f[i-1][j]+a[i].f);	
            if(j>=d&&f[i][j]!=-1)
                ans=min(ans,a[i].t);
        }
    }
    
    if(ans==100000007)
    {
        ans=10;
        for(i=1;i<=g;i++)
        {
            if(a[i].t>ans) break;
            ans+=a[i].f;
        }
    }
    printf("%d",ans);
    return 0;
        
}

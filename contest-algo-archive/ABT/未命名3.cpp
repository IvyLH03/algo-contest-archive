//Love and Freedom.
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define inf 20021225
#define N 100010
using namespace std;
int read()
{
    int s=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return f*s;
}
int a[N<<1],n,tmp[3],b[N<<1];
int main()
{
    n=read();
    for(int i=1;i<(n<<1);i++)
        a[i]=read();
    for(int i=n;i;i--)
    {
        for(int j=2;j<n;j++)
        {
            tmp[0]=a[j-1]; tmp[1]=a[j]; tmp[2]=a[j+1];
            sort(tmp,tmp+3); b[j-1]=tmp[1];
        }
        for(int j=1;j<n-1;j++)    a[j]=b[j];
		for(int j=1;j<=n;j++) printf("%d ",a[j]); printf("\n");
    }
    
    printf("%d\n",a[1]);
    return 0;
}

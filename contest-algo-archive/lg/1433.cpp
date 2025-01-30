#include<cstdio>
#include<cmath>
using namespace std;
int n;
double a[16][3];//a:第n块,1=x,2=y;
double dist[16][16],ans;//dist:距离,[0][i]表示(0,0)至第i块的距离
bool bz[16]; 
void dfs(int l,double s,int t)
{
	if(s>ans)
		return;
		
	if(t>n)
	{
		if(s<ans)
			ans=s;
		return;
	}
	
	int i;
	for(i=1;i<=n;i++)
	{
		if(!bz[i])
		{
			bz[i]=1;
			dfs(i,s+dist[l][i],t+1);
			bz[i]=0;
		}
	}
	
}
int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++){
    	scanf("%lf%lf",&a[i][1],&a[i][2]);
        dist[0][i]=sqrt(a[i][1]*a[i][1]+a[i][2]*a[i][2]);
    }
    
    for(i=1;i<n;i++){
    	for(j=i+1;j<=n;j++)
    		dist[i][j]=dist[j][i]=sqrt((a[i][1]-a[j][1])*(a[i][1]-a[j][1])
			+(a[i][2]-a[j][2])*(a[i][2]-a[j][2]));
    }
    
    
    				//for(i=1;i<=n;i++){
    				//	for(j=1;j<=n;j++)
    				//		printf("%d=>%d:%lf  ",i,j,dist[i][j]);
    				//	printf("\n");
    				//		
    				//}
    
    
    ans=10000001;
    dfs(0,0,1);
    printf("%.2lf",ans);
    return 0;
}

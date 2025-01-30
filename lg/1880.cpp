#include<cstdio>
#include<cstring>
int max(int a,int b)
{
	return a>b?a:b;
} 
int min(int a,int b)
{
	return a>b?b:a;
}
int n,f1[101][101],f2[101][101],s[101];
int main()
{
	scanf("%d",&n);
	int i,a,j,k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		s[i]=s[i-1]+a;
		s[i+n]=s[i+n-1]+a;
	}
	memset(f2,1,sizeof(f2));
	
	for(i=1;i<=2*n;i++);
	{
		f2[i][i]=f1[i][i]=s[i]-s[i-1];
	}
	
	for(i=n;i<=2*n;i++)
		for(j=i+1;j<=2*n;j++)
			for(k=i+1;k<=j;k++)
			{
				f1[i][j]=max(f1[i][j],f1[i][k]+f1[k+1][j]+s[j]-s[i-1]);
				f2[i][j]=min(f2[i][j],f2[i][k]+f2[k+1][j]+s[j]-s[i-1]);
			}
	int maxl=0,minl=0x7ffffff;
	for(i=1;i<=2*n;i++)
		for(j=1;j<=2*n;j++)
		if(i!=j) 
		{
			maxl=max(maxl,f1[i][j]);
			minl=min(minl,f2[i][j]);
		}
		
	printf("%d\n%d",minl,maxl);
	return 0;
} 

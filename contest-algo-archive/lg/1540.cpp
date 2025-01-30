#include<cstdio>
using namespace std;
int m,n,a[1001],b[101],ans;
int main()
{
	scanf("%d%d",&m,&n);
	int i,j,len=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		bool flag=0;
		if(len<m)
		{
			for(j=1;j<=len;j++)
				if(b[j]==a[i]){
					flag=1;break;
				}
			if(flag)
				continue;
			b[++len]=a[i];
			ans++;
		}
		else
		{
			for(j=1;j<=m;j++)
				if(b[j]==a[i]){
					flag=1;break;
				}
			if(flag)
				continue;
			for(j=1;j<=m-1;j++)
			{
				b[j]=b[j+1];
			}
			b[m]=a[i];
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

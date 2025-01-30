#include<cstdio>
using namespace std;
bool a[101][101],b[101][101];
int main()
{
	int m,n,i,j;
	float s=0;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++);
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&b[i][j]);
			if(b[i][j]==a[i][j]) s++;
		}
		
	s=s/(m*n)*100;
	printf("%.2f",s);
	
}

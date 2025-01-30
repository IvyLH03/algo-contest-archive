#include<cstdio> 
#include<algorithm>
#include<cstring>
using namespace std;
char x[201],y[201];
int f[201][201];
int main()
{
	scanf("%s%s",x,y);
	int lenx=strlen(x),leny=strlen(y);
	int i,j;
	for(i=1;i<=lenx;i++)
		for(j=1;j<=leny;j++)
		{
			f[i][j]=max(f[i][j-1],f[i-1][j]);
			if(x[i-1]==y[j-1])
				f[i][j]=max(f[i][j],f[i-1][j-1]+1);
		}
	printf("%d",f[lenx][leny]);
	return 0;
}

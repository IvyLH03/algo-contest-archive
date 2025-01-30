#include<cstdio>
using namespace std;
const int N=400;
int n,x,y,a[N],b[N],yx,yy;
int sf[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};	
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	int i;
	for(i=1;i<=x;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=y;i++)	
		scanf("%d",&b[i]);
	int tx=1,ty=1;
	while(n--)
	{
		if(tx>x) tx=1;
		if(ty>y) ty=1;
		if(sf[a[tx]][b[ty]]) yx++;
		if(sf[b[ty]][a[tx]]) yy++;
		tx++;ty++;
	}	
	printf("%d %d",yx,yy);
	return 0;
}

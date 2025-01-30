#include<cstdio>
#include<cmath>
using namespace std;
int s,v,tot,h,m;
int main()
{
	scanf("%d%d",&s,&v);
	tot=ceil(1.0*s/v)+10;
	if(tot>480)
	{
		tot-=480;
		h=23-tot/60,m=60-tot%60;
	}
	else
	{
		h=7-tot/60,m=60-tot%60;
	}
	if(h<10) printf("0");
	printf("%d:",h);
	if(m<10) printf("0");
	printf("%d",m);
	return 0;
	
}

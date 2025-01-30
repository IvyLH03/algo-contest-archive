#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int m,n,tot,j;
char s[11][11];
struct node{
	int time;
	char clr[11];
}a[101]; 
bool comp(node a,node b)
{
	return a.clr<b.clr;
}
void ac()
{
	char ncl[11];
	strcpy(ncl,a[j].clr);
	int b=a[j].time,g=0;
	while(!strcmp(ncl,a[++j].clr))
	{
		if(b>g) g+=a[j].time;
		else b+=a[j].time;
	}
	tot+=max(b,g);
}
int main()
{
	int i,j,k;
	scanf("%d%d",&m,&n);
	while(m||n)
	{
		for(i=1;i<=m;i++)
			scanf("%s",s[i]);
		for(i=1;i<=n;i++)
			scanf("%d%s",&a[i].time,a[i].clr);
		sort(a+1,a+1+n,comp);
		j=0;
		for(i=1;i<=m;i++)
		{
			if(++j>n) break;
			ac();
		}
		printf("%d\n",tot);
		scanf("%d%d",&m,&n);
	}
	return 0;
}

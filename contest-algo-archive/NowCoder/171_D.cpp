#include<cstdio>
using namespace std;
int n,m,iqn[150],iqa[150],facea[150],iq,face,s;
void dfs(int t)
{
	if(t==n+1)
	{
		if(s>face)
			face=s;
		return; 
	}
	int i;
	bool fli=0,flf=0;
	for(i=1;i<=m;i++)
	{
		if(iq>=iqn[i]&&(iqa[i]||facea[i]))
		{
			iq+=iqa[i];
			s+=facea[i];
			if(iqa[i]>0)   {iqa[i]--;fli=1;}
			if(facea[i]>0) {facea[i]--;flf=1;}
			dfs(t+1);
			if(flf)  {facea[i]++;flf=0;}
			if(fli)  {iqa[i]++;fli=0;}
			s-=facea[i];
			iq-=iqa[i];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&iqn[i],&iqa[i],&facea[i]);
	dfs(1);
	printf("%d",face);
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int f,s[1007],tot;
	bool stf;	//覆盖到了(ma) 
}a[1007];
struct node2{
	int d,num;
}r[1007];
bool comp(node2 x,node2 y)
{
	return x.d>y.d;
}
void bz(int x,bool ns) //ns=0:x是建了消防站的那个点 
{				   //ns=1:x是建了消防站的那个点的儿子或者父亲 
	int i; 
	for(i=1;i<=a[x].tot;i++)
		a[a[x].s[i]].stf=1;
	if(!ns)
	{
		for(i=1;i<=a[x].tot;i++)
		{ 	
			if(a[a[x].s[i]].tot)
				bz(a[x].s[i],1);
		} 
		if(a[a[x].f].tot)
			bz(a[x].f,1);
	}
}
void dfs(int x,int d)
{
	int i;
	if(d>2)
		return;
	a[x].stf=1;
	for(i=1;i<=a[x].tot;i++)
		dfs(a[x].s[i],d+1);
}
int main()
{
	int i,b,n,tot=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		r[i].num=i;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&b);
		a[i].f=b;
		a[b].s[++a[b].tot]=i;
		r[i].d=r[b].d+1;
	} 
	sort(r+1,r+1+n,comp);
						//	for(i=1;i<=n;i++)
						//	printf("%d:%d\n",r[i].num,r[i].d);

	for(i=1;i<=n;i++)
		if(!a[r[i].num].stf)
		{
			tot++;
			if(r[i].d>=2)
			{
				//a[a[a[r[i].num].f].f].stf=1;
				//bz(a[a[r[i].num].f].f,0);
				dfs(a[a[r[i].num].f].f,0);
				dfs(a[a[a[r[i].num].f].f].f,1);
				a[a[a[a[a[r[i].num].f].f].f].f].stf=1;
				
			}
			else 
			{
				if(r[i].d==1)
				{
					//a[a[r[i].num].f].stf=1;
					//bz(a[r[i].num].f,0);
					dfs(a[r[i].num].f,1);
				}
				else
				{	
					a[r[i].num].stf=1;
				 	//bz(r[i].num,1);
				}
			}
			
		}

	printf("%d",tot);
	return 0;
}

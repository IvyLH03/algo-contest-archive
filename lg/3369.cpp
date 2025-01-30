#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6,INF=1e8;
int n,tot,rt;
struct node{
	int val,lc,rc,size,pri,cnt;
	#define v(x) a[x].val
	#define ls(x) a[x].lc
	#define rs(x) a[x].rc
	#define s(x) a[x].size
	#define p(x) a[x].pri
	#define c(x) a[x].cnt
}a[40*N];
void upt(int k){
	s(k)=s(ls(k))+s(rs(k))+c(k);
}
void lturn(int &k){
	int y=rs(k);
	rs(k)=ls(y);
	ls(y)=k;k=y;
	upt(ls(k));upt(k);
}
void rturn(int &k){
	int y=ls(k);
	ls(k)=rs(y);
	rs(y)=k;k=y;
	upt(rs(k));upt(k);
}
void Insert(int &k,const int key)
{		//	printf("*");
	if(!k)							
	{											//	printf("^");
		k=++tot;v(k)=key;s(k)=1;p(k)=rand();
		c(k)=1;ls(k)=rs(k)=0;
		return ;
	}
	++s(k);
	if(v(k)==key)
	{
		c(k)++;return;
	}
	if(key<v(k))
	{
		Insert(ls(k),key);
		if(p(ls(k))<p(k)) rturn(k);
	}
	else
	{
		Insert(rs(k),key);
		if(p(rs(k))<p(k)) lturn(k);
	}
	upt(k);
}
void del(int &k,const int key)
{
	if(v(k)==key)
	{
		if(c(k)>1)	
		{
			c(k)--;s(k)--;return;
		}
		if(!(ls(k)&&rs(k)))
		{
			k=ls(k)+rs(k);	//因为k直接取址 
		}
		else
		{
			if(p(ls(k))<p(rs(k)))
			{
				rturn(k);del(k,key);
			}
			else
			{
				lturn(k);del(k,key);
			}
		}
		return;
	}
	s(k)--;
	if(key<v(k)) del(ls(k),key);
	else del(rs(k),key);
}
int FindRank(int &k,const int key)
{
	if(v(k)==key)
		return s(ls(k))+1;
	if(key<v(k))
		return FindRank(ls(k),key);
	else
		return FindRank(rs(k),key)+s(ls(k));
}
int FindRankNum(const int key)//用的时候cnt初值要设成s(ls(1))+1 
{
	//if(cnt==key) return v(k);
//	if(cnt>key)
//	{
//		cnt-=s(rs(ls(k)))+1;
//		return FindRankNum(ls(k),key,cnt);
//	} 
//	cnt+=s(ls(rs(k)))+1;
//	return FindRankNum(rs(k),key,cnt);
	int x=rt,cnt=s(ls(1))+1;
	while(x)
	{
		if(cnt==x) return v(x);
		if(cnt>key)
		{
			cnt-=s(rs(ls(x)))+1;x=ls(x);
		}
		else
		{
			cnt+=s(ls(rs(x)))+1;x=rs(x);
		}
	}
} 
int MaxLow(int &k,const int key)	//如果他是他爸的右儿子，那就是他爸的左儿子的右儿子的右儿子的右儿子……的右儿子 
{									//如果他是他爸的左儿子，那就是他的右儿子的右儿子的右儿子的右儿子……的右儿子 
	int x=rt,res;
	while(x)
	{
		if(v(x)<key)
		{
			res=v(x);x=rs(x);
		}
		else x=ls(x);
	}
	return res;
}
int MinUp(int &k,const int key)
{
	int x=k,res=-INF;
	while(x)
	{
		if(v(x)>=key)
		{
			res=v(x);x=ls(x);
		}
		else x=rs(x);
	} 
	return res;
}
int main()
{
	freopen("3369.out","w",stdout);
	int i,x,y,ans;
	scanf("%d%d%d",&n,&x,&y);
	Insert(rt,y);
	for(i=2;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
	 
		if(x==1) Insert(rt,y);
		else if(x==2) del(rt,y);
		else if(x==3) printf("%d\n",FindRank(rt,y));
		else if(x==4) printf("%d\n",FindRankNum(y));
		else if(x==5) printf("%d\n",MaxLow(rt,y));
		else if(x==6) printf("%d\n",MinUp(rt,y));
	}
	return 0;
}

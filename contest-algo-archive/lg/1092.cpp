#include<cstdio>
#include<cstring>
using namespace std;
int n,rs[27];
char s[4][27];
bool bz[27];
int bh(char c)
{
	return c-'A'+1;
}
void search(int x,int y,int t)
{
	int i,w1,w2,w3;
	if(x==-1)
	{
		if(t==0)
		{
			for(i=1;i<=n-1;i++)
				printf("%d ",rs[i]);
			printf("%d\n",rs[n]);
		}
		return;
	}
	for(i=x-1;i>=1;i--)
	{
		w1=rs[bh(s[1][i])];
		w2=rs[bh(s[2][i])];
		w3=rs[bh(s[3][i])];
		if(w1==-1||w2==-1||w3==-1)continue;
		if((w1+w2)%n!=w3&&(w1+w2+1)%n!=w3)return;
	}
	if(rs[bh(s[y][x])]==-1)
	{
		for(i=n-1;i>=0;i--)
		{
			if(y!=3)
			{
				
					if(!bz[i])
					{
						bz[i]=1;
						rs[bh(s[y][x])]=i;
						search(x,y+1,t);
						bz[i]=0;rs[bh(s[y][x])]=-1;
					}
			} 
			else
			{
				int w=(rs[bh(s[1][x])]+rs[bh(s[2][x])]+t);
				if(w%n!=i)continue;
				rs[bh(s[3][x])]=i;
				bz[i]=1;
				search(x-1,1,w/n);
				rs[bh(s[3][x])]=-1;bz[i]=0;
			}
		}
	}
	else
	{
		if(y==3)
		{
			int w=(rs[bh(s[1][x])]+rs[bh(s[2][x])]+t);
			if(w%n!=rs[bh(s[3][x])])
				return;
			search(x-1,1,w/n);
		}
		else search(x,y+1,t);
	}
	
}
int main()
{
	int i;
	scanf("%d\n",&n);
	for(i=1;i<=3;i++)
		scanf("%s",s[i]);
	memset(rs,-1,sizeof(rs));
	search(n-1,1,0);
	return 0;
}

#include<cstdio>//2741      输出太多懒得做了
#include<queue>
#include<algorithm>
const int N=37,INF=90;
char map[N][N];
int h,w,e[N],head[N],num,tot,used[27],q,ans[27];
bool use[N],vis[N][N];
struct node{
	int to,next;
}a[N];
struct node2{
	int maxx,maxy,minx,miny;//(maxx,maxy)==右上角；(minx,miny)==左上角 
}b[N];
queue<int>que;
void add(int x,int y)//增加一条x到y的边 
{
	a[++num].next=head[x];
	a[num].to=y;e[y]++;
	head[x]=num;
}
void check(int x,int y,int i)
{
	q=map[x][y]-'A'+1;
	if(q!=used[i]&&!vis[i][q])
	{
		vis[i][q]=vis[q][i]=1;add(q,i);
	}
}
int main()
{
	int i,j,x,y;
	scanf("%d%d",&h,&w);
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
			scanf("%c",&map[i][j]);
			if(map[i][j]>='A'&&map[i][j]<='Z')use[map[i][j]-'A'+1]=1;
		getchar();
	}
	for(i=1;i<=26;i++)
		if(use[i]) used[++tot]=i;
	for(i=1;i<=tot;i++)
	{
		b[i].minx=b[i].miny=INF;
	}
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
			if(map[i][j]!='.')
			{
				q=map[i][j]-'A'+1;
				b[q].maxx=i;
				b[q].maxy=max(b[q].maxy,j);
				b[q].minx=min(b[q].minx,i);
				b[q].miny=min(b[q].miny,j);
			}
	}
	for(i=1;i<=tot;i++)
	{
		for(j=b[i].miny;j<=b[i].maxy;j++)
		{
			check(b[i].minx,j,i);
			check(b[i].maxx,j,i);
		}
		for(j=b[i].minx+1;j<=b[i].maxx-1;j++) 
		{
			check(j,b[i].miny,i);
			check(j,b[i].maxy,i);

		}
	}
	
	for(i=1;i<=tot;i++)
	{
		if(!e[i]) que.push(i);
	}
	while(!que.empty())
	{
		q=que.top();
		que.pop();
		i=head[q];
		while(i)
		{
			e[a[i].to]--;
			if(!e[a[i].to])
			{
				
			}
		}
		
	}
}

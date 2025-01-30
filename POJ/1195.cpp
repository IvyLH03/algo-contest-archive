#include<cstdio>
#include<algorithm>
#define sul(x) (x<<2)+1
#define sur(x) (x<<2)+2
#define sdl(x) (x<<2)+3
#define sdr(x) (x<<2)+4
using namespace std;
const int N=1027;
int n,t[N*N];
void change(int x,int l,int r,int u,int d,int xx,int yy,int v)
{
//	printf("x=%d,l=%d,r=%d,u=%d,d=%d,xx=%d,yy=%d\n",x,l,r,u,d,xx,yy); 
	if(l>xx||r<xx||u>yy||d<yy) return;
	if(l==r&&u==d)
	{
		t[x]+=v;return;
	}
	int midx=l+(r-l>>1),midy=u+(d-u>>1);
	if(midx>=xx&&midy>=yy) change(sul(x),l,midx,u,midy,xx,yy,v);
	if(midx>=xx&&midy<yy&&u!=d) change(sdl(x),l,midx,midy+1,d,xx,yy,v);
	if(midx<xx&&midy>=yy&&l!=r) change(sur(x),midx+1,r,u,midy,xx,yy,v);
	if(midx<xx&&midy<yy&&u!=d&&l!=r) change(sdr(x),midx+1,r,midy+1,d,xx,yy,v);
	t[x]=t[sul(x)]+t[sdl(x)]+t[sur(x)]+t[sdr(x)];
}
int query(int x,int l,int r,int u,int d,int ll,int rr,int uu,int dd)
{
	if(l>rr||r<ll||u>dd||d<uu) return 0;
	if(l>=ll&&r<=rr&&u>=uu&&d<=dd) return t[x];
	int midx=l+(r-l>>1),midy=u+(d-u>>1),s=0;
	if(midx>=ll&&midy>=uu) s=query(sul(x),l,midx,u,midy,ll,rr,uu,dd);
	if(midx>=ll&&midy<dd&&u!=d) s+=query(sdl(x),l,midx,midy+1,d,ll,rr,uu,dd);
	if(midx<rr&&midy>=uu&&l!=r) s+=query(sur(x),midx+1,r,u,midy,ll,rr,uu,dd);
	if(midx<rr&&midy<dd&&l!=r&&u!=d) s+=query(sdr(x),midx+1,r,midy+1,d,ll,rr,uu,dd);
	return s;
}
int main()
{
	int k,x,y,l,r,u,d,v;
	scanf("%d%d",&k,&n);
	while(1)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d%d",&x,&y,&v);
			change(0,1,n,1,n,x,y,v);
		}
		else if(k==2)
		{
			scanf("%d%d%d%d",&l,&u,&r,&d);
			printf("%d\n",query(0,1,n,1,n,l,r,u,d));
		}
		else break;
	//	for(int i=0;i<=20;i++) printf("%d ",t[i]); printf("\n");
	}
	return 0;
}

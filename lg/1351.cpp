#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200007,Mod=10007;
int fs[N],fmax[N],a[N],n,head[N],etot,res;
struct node{
	int next,to;
}e[N<<1];
void adde(int x,int y)
{
	e[++etot].to=y;
	e[etot].next=head[x];
	head[x]=etot;
}
void dfs(int x,int f)
{
	int res=0,res2=0,maxn1=0,maxn2=0; 
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].to==f) continue;
		dfs(e[i].to,x);
		fs[f]+=a[e[i].to]*a[f]*2;fmax[f]=max(fmax[f],a[e[i].to]*a[f]);
		fs[x]+=fs[e[i].to]+(e[i].to*res*2)%Mod;fmax[x]=max(fmax[x],fmax[e[i].to]);
		fs[f]%=Mod;fs[x]%=Mod;
		res+=e[i].to;
		if(a[e[i].to]>maxn1) maxn1=a[e[i].to]; 
		else if(a[e[i].to]>maxn2) maxn2=a[e[i].to];
		//for(int j=e[i].next;j;j=e[j].next)
	//	{
	//		if(e[j].to==f) continue;
	//		fs[x]+=a[e[i].to]*a[e[j].to]*2;fs[x]%=Mod;
	//		fmax[x]=max(fmax[x],a[e[i].to]*a[e[j].to]);
	//	}
	}
	fmax[x]=max(fmax[x],maxn1*maxn2);
//	fs[f]=(fs[f]+res*res-res2)%Mod;
}
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<n;i++) 
	{
		scanf("%d%d",&x,&y);
		adde(x,y);adde(y,x);
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,0);
	printf("%d %d\n",fmax[1],fs[1]%Mod);
	return 0;
}

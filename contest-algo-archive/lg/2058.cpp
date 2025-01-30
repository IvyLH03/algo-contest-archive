#include<cstdio>
using namespace std;
const int N=100006;
int a[N],b[N],w[N],t[N],cutT,curHead,curNum[N],curShipHead,cnt,curCnt[N],n;
int main()
{
	scanf("%d",&n);
	int curShipPassNum,x;
	curShipHead=curHead=1;
	scanf("%d%d",&t[i],&curShipPassNum);
	for(int i=1;i<=curShipPassNum)
	{
		scanf("%d",&x);
		curCnt[x]++;
	}
	for(int i=1;i<N;i++)
	{
		if(curCnt[i])
		{
			cnt++;
			curNum[i]+=curCnt[i];
			a[++a[0]]=i
			b[a[0]]=curCnt[i]; 
		} 
	}
	w[1]=a[0];
	curT=t[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%d%d",&t[i],&x);
		while(t[i]-curT>=86400)
		{
			while(curHead<=w[curShip])
			{
				curNum[a[curHead]]-=b[curHead];
				if(!curNum[a[curHead]]) cnt--;
			}
			curT=t[++curShip];
		}
	}
}

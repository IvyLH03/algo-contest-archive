#include<cstdio>
#include<cstring>
using namespace std;
char sname[101][21],xsgb[101],xbxs[101];
int qimo[101],banji[101],lunwen[101],grzong[101];
int main()
{
	int i,n,zong=0,temp=0,maxn=0,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s %d %d %c %c %d",sname[i],&qimo[i],&banji[i],&xsgb[i],&xbxs[i],&lunwen[i]);
		//printf("%d",i);
	}
	for(i=1;i<=n;i++)
	{
		if((qimo[i]>80)&&(lunwen[i]>0)) temp+=8000;
		if((qimo[i]>85)&&(banji[i]>80)) temp+=4000;
		if(qimo[i]>90) temp+=2000;
		if((qimo[i]>85)&&(xbxs[i]=='Y')) temp+=1000;
		if((banji[i]>80)&&(xsgb[i]=='Y')) temp+=850;
		zong+=temp;
		if(temp>maxn){y=i;maxn=temp;}
		temp=0;
	}
	printf("%s\n%d\n%d\n",sname[y],maxn,zong);
	return 0;
}

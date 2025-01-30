#include<cstdio>
#include<cmath>
using namespace std;
float a[301];
int main()
{
	int n,i;
	float maxn,minn,s=0,aver,maxnrd=0,minnrd,wucha;
	scanf("%d",&n);
	
	scanf("%f",&a[1]);
	maxn=a[1];
	minn=a[1];
	s+=a[1];
	
	for(i=2;i<=n;i++)
	{
		scanf("%f",&a[i]);
		if(a[i]>maxn) maxn=a[i];
		if(a[i]<minn) minn=a[i];
		s+=a[i];
	}
	
	minnrd=maxn;
	
	for(i=1;i<=n;i++)
		if(a[i]!=maxn&&a[i]!=minn)
		{
			if(a[i]>maxnrd) maxnrd=a[i];
			if(a[i]<minnrd) minnrd=a[i];	
		}
	
	aver=(s-maxn-minn)/(n-2);
	wucha=abs(maxnrd-aver)>abs(minnrd-aver)? abs(maxnrd-aver):abs(minnrd-aver);
	
	
	printf("%.2f %.2f",aver,wucha);
	
	return 0;
}
